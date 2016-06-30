// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent))
class BATTLETANK_04_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UTankBarrel();

	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere, Category="SetUp")
	float MaxDegreesPerSecond;

	UPROPERTY(EditAnywhere, Category = "SetUp")
	float MaxElevationDegrees;

	UPROPERTY(EditAnywhere, Category = "SetUp")
	float MinElevationDegrees;
};