// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank_04.h"
#include "../Public/TankBarrel.h"
#include "../Public/TankTurret.h"
#include "../Public/TankAimingComponent.h"

UTankAimingComponent::UTankAimingComponent()
{
	bWantsBeginPlay = false;
	PrimaryComponentTick.bCanEverTick = false;

	Barrel = nullptr;
	Turret = nullptr;
	FiringState = EFiringState::Reloading;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator AimRotation = AimDirection.Rotation();
	FRotator DeltaRotator = AimRotation - BarrelRotation;

	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate (DeltaRotator.Yaw);
}

void UTankAimingComponent::AimAt(FVector AimLocation, float LaunchSpeed)
{
	if (Barrel)
	{
		FVector LaunchVelocity;
		FVector StartLocation = Barrel->GetSocketLocation(FName("Cannon"));
		if (UGameplayStatics::SuggestProjectileVelocity(GetWorld(), LaunchVelocity, StartLocation, AimLocation, LaunchSpeed, false, 0.0f, 0.0f, ESuggestProjVelocityTraceOption::DoNotTrace))
		{
			FVector AimDirection = LaunchVelocity.GetSafeNormal();
			UTankAimingComponent::MoveBarrelTowards(AimDirection);
		}
	}
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* Barrel)
{
	this->Barrel = Barrel;
}

class UTankBarrel* UTankAimingComponent::GetBarrelReference()
{
	return this->Barrel;
}

void UTankAimingComponent::SetTurretReference(class UTankTurret* Turret)
{
	this->Turret = Turret;
}

class UTankTurret* UTankAimingComponent::GetTurretReference()
{
	return this->Turret;
}
