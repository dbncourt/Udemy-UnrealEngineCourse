// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank_04.h"
#include "../Public/TankPlayerController.h"
#include "../Public/Tank.h"

ATankPlayerController::ATankPlayerController()
{
	this->CrossHairXLocation = 0.5f;
	this->CrossHairYLocation = 0.33333f;
	this->LineTraceRange = 1000000.0f;
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* ControlledTank = ATankPlayerController::GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing %s"), *ControlledTank->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ATankPlayerController::AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (ATankPlayerController::GetControlledTank())
	{
		FVector HitLocation;
		if (ATankPlayerController::GetSightRayHitLocation(HitLocation))
		{
			ATankPlayerController::GetControlledTank()->AimAt(HitLocation);
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
		ATankPlayerController::GetLookVectorHitLocation(LookDirection, HitLocation);
		return true;
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

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return this->DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}