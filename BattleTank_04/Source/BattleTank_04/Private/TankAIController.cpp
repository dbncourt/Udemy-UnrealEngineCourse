// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank_04.h"
#include "../Public/TankAIController.h"
#include "../Public/TankAimingComponent.h"

ATankAIController::ATankAIController()
{
	AcceptanceRadius = 3000.0f;
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	APawn* PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	APawn* ControlledTank = GetPawn();

	if (ensure(PlayerTank))
	{
		MoveToActor(PlayerTank, AcceptanceRadius);
		UTankAimingComponent* TankAimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		if (ensure(TankAimingComponent))
		{
			TankAimingComponent->AimAt(PlayerTank->GetActorLocation());
			TankAimingComponent->Fire();
		}
	}
}

