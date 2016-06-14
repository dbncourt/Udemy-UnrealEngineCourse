// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank_04.h"
#include "TankPlayerController.h"

ATankPlayerController::ATankPlayerController()
{
	this->CrossHairXLocation = 0.5f;
	this->CrossHairYLocation = 0.33333f;
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
			UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());
		}
		
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation) const
{
	int32 ViewportSizeX;
	int32 ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation = FVector2D((ViewportSizeX * this->CrossHairXLocation), (ViewportSizeY * this->CrossHairYLocation));

	HitLocation = FVector(1.0f);
	return true;
}
