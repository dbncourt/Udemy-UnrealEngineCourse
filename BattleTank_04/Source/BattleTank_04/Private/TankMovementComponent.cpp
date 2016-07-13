// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank_04.h"
#include "../Public/TankTrack.h"
#include "TankMovementComponent.h"

UTankMovementComponent::UTankMovementComponent()
{
	RightTrack = nullptr;
	LeftTrack = nullptr;
}

void UTankMovementComponent::MoveForward(float Throw)
{
	if (RightTrack && LeftTrack)
	{
		RightTrack->SetThrottle(Throw);
		LeftTrack->SetThrottle(Throw);
	}
}

void UTankMovementComponent::TurnRight(float Throw)
{
	if (RightTrack && LeftTrack)
	{
		RightTrack->SetThrottle(-Throw);
		LeftTrack->SetThrottle(Throw);
	}
}

void UTankMovementComponent::Initialize(UTankTrack* RightTrack, UTankTrack* LeftTrack)
{
	this->RightTrack = RightTrack;
	this->LeftTrack = LeftTrack;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT("%s MoveVelocity: %s"), *GetOwner()->GetName(), *MoveVelocity.ToString());
}