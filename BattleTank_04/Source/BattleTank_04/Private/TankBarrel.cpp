// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank_04.h"
#include "../Public/TankBarrel.h"

UTankBarrel::UTankBarrel()
{
	this->MaxDegreesPerSecond = 20.0f;

	this->MaxElevationDegrees = 40.0f;
	this->MinElevationDegrees = 0.0f;
}

void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);
	float ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	float Elevation = FMath::Clamp<float>(RawNewElevation, this->MinElevationDegrees, this->MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0.0f, 0.0f));
}