// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank_04.h"
#include "TankTurret.h"

UTankTurret::UTankTurret()
{
	this->MaxDegreesPerSecond = 25.0f;
}

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);
	float RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float Rotation = RelativeRotation.Yaw + RotationChange;
	this->SetRelativeRotation(FRotator(0.0f, Rotation, 0.0f));
}