// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank_04.h"
#include "TankMovementComponent.h"

UTankMovementComponent::UTankMovementComponent()
{
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend Move Forward Throw: %f"), Throw)
}