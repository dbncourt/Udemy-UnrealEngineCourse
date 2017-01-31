// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank_04.h"
#include "../Public/TankPlayerController.h"
#include "../Public/TankAimingComponent.h"
#include "Tank.h"

ATankPlayerController::ATankPlayerController()
{
	this->CrossHairXLocation = 0.5f;
	this->CrossHairYLocation = 0.33333f;
	this->LineTraceRange = 1000000.0f;
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UTankAimingComponent* TankAimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (ensure(TankAimingComponent))
	{
		ATankPlayerController::FoundAimingComponent(TankAimingComponent);
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ATankPlayerController::AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (GetPawn())
	{
		UTankAimingComponent* TankAimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
		if (ensure(TankAimingComponent))
		{
			FVector HitLocation;
			if (ATankPlayerController::GetSightRayHitLocation(HitLocation))
			{
				TankAimingComponent->AimAt(HitLocation);
			}
		}
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation) const
{
	int32 ViewportSizeX;
	int32 ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation = FVector2D((ViewportSizeX * this->CrossHairXLocation), (ViewportSizeY * this->CrossHairYLocation));
	FVector LookDirection;
	
	if(ATankPlayerController::GetLookDirection(ScreenLocation, LookDirection))
	{
		return ATankPlayerController::GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	else
	{
		return false;
	}
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector& LookDirection, FVector& HitLocation) const
{
	FVector Start = PlayerCameraManager->GetCameraLocation();
	FVector End = Start + (LookDirection * this->LineTraceRange);
	FHitResult HitResult;

	if(GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}

	return false;
}

void ATankPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		ATank* PossessedTank = Cast<ATank>(InPawn);
		if (ensure(PossessedTank))
		{
			PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankPlayerController::OnPossedTankDeath);
		}
	}
}

void ATankPlayerController::OnPossedTankDeath()
{
	APlayerController::StartSpectatingOnly();
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return this->DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}