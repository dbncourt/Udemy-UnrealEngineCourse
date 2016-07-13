// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank_04.h"
#include "../Public/TankTrack.h"
#include "TankMovementComponent.h"

UTankMovementComponent::UTankMovementComponent()
{
	RightTrack = nullptr;
	LeftTrack = nullptr;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend Move Forward Throw: %f"), Throw)

	RightTrack->SetThrottle(Throw);
	LeftTrack->SetThrottle(Throw);
}

void UTankMovementComponent::Initialize(UTankTrack* RightTrack, UTankTrack* LeftTrack)
{
	if (RightTrack && LeftTrack)
	{
		this->RightTrack = RightTrack;
		this->LeftTrack = LeftTrack;
	}
}