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
}