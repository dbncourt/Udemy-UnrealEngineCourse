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
	if (ensure(RightTrack && LeftTrack))
	{
		RightTrack->SetThrottle(Throw);
		LeftTrack->SetThrottle(Throw);
	}
}

void UTankMovementComponent::TurnRight(float Throw)
{
	if (ensure(RightTrack && LeftTrack))
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
	FVector TankForwardVector = GetOwner()->GetActorForwardVector().GetSafeNormal();
	FVector ForwardIntentionVector = MoveVelocity.GetSafeNormal();
	FVector PerpendicularVector = GetOwner()->GetActorUpVector().GetSafeNormal();

	float ForwardThrow = FVector::DotProduct(TankForwardVector, ForwardIntentionVector);
	UTankMovementComponent::MoveForward(ForwardThrow);
	
	float RightThrow = FVector::CrossProduct(TankForwardVector, ForwardIntentionVector).Z;
	UTankMovementComponent::TurnRight(RightThrow);
}