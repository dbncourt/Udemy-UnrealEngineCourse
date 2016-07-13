// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_04_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UTankMovementComponent();

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void MoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void TurnRight(float Throw);

	UFUNCTION(BlueprintCallable, Category = "SetUp")
	void Initialize(class UTankTrack* RightTrack, class UTankTrack* LeftTrack);

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

private:
	class UTankTrack* RightTrack;

	class UTankTrack* LeftTrack;
};