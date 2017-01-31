// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank_04.h"
#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Tank.h"

ATankAIController::ATankAIController()
{
	AcceptanceRadius = 10000.0f;
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

			if (TankAimingComponent->GetFiringState() == EFiringState::Locked)
			{
				TankAimingComponent->Fire();
			}
		}
	}
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		ATank* PossessedTank = Cast<ATank>(InPawn);
		if (ensure(PossessedTank))
		{
			PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossedTankDeath);
		}
	}
}

void ATankAIController::OnPossedTankDeath()
{
	APawn* TankPawn = AController::GetPawn();
	if (TankPawn)
	{
		TankPawn->DetachFromControllerPendingDestroy();
	}
}