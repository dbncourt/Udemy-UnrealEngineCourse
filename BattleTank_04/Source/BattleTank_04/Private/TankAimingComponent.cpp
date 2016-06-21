// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank_04.h"
#include "../Public/TankBarrel.h"
#include "../Public/TankAimingComponent.h"

UTankAimingComponent::UTankAimingComponent()
{
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::RotateBarrel(FVector AimDirection)
{
	FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator AimRotation = AimDirection.Rotation();
	FRotator DeltaRotator = AimRotation - BarrelRotation;

	Barrel->Elevate(5.0f);

	UE_LOG(LogTemp, Warning, TEXT("AimRotation: %s"), *AimRotation.ToString());
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
			UTankAimingComponent::RotateBarrel(AimDirection);
			//UE_LOG(LogTemp, Warning, TEXT("%s Aiming At: %s"), *GetOwner()->GetName(), *AimDirection.ToString());
		}
	}
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* Barrel)
{
	this->Barrel = Barrel;
}