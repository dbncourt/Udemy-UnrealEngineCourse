// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_04_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UTankTurret();

	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = "SetUp")
	float MaxDegreesPerSecond;
};