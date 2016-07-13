// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_04_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	ATankAIController();

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	float AcceptanceRadius;
};
