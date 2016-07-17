// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank_04.h"
#include "../Public/TankBarrel.h"
#include "../Public/TankTurret.h"
#include "../Public/Projectile.h"
#include "../Public/TankAimingComponent.h"

UTankAimingComponent::UTankAimingComponent()
{
	bWantsBeginPlay = false;
	PrimaryComponentTick.bCanEverTick = false;

	Barrel = nullptr;
	Turret = nullptr;
	FiringState = EFiringState::Locked;

	LaunchSpeed = 4000.0f;
	LastFireTime = 0.0;
	ReloadTime = 3.0;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	if (ensure(Barrel) && ensure(Turret))
	{
		FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
		FRotator AimRotation = AimDirection.Rotation();
		FRotator DeltaRotator = AimRotation - BarrelRotation;

		Barrel->Elevate(DeltaRotator.Pitch);
		Turret->Rotate(DeltaRotator.Yaw);
	}
}

void UTankAimingComponent::AimAt(FVector AimLocation)
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

void UTankAimingComponent::Initialize(class UTankBarrel* Barrel, class UTankTurret* Turret)
{
	this->Barrel = Barrel;
	this->Turret = Turret;
}

void UTankAimingComponent::Fire()
{
	bool IsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTime;

	if (IsReloaded)
	{
		if (ensure(Projectile) && ensure(Barrel))
		{
			FVector ProjectileLocation = Barrel->GetSocketLocation("Cannon");
			FRotator ProjectileRotation = Barrel->GetSocketRotation("Cannon");

			AProjectile* SpawnedProjectile = GetWorld()->SpawnActor<AProjectile>(this->Projectile, ProjectileLocation, ProjectileRotation);
			SpawnedProjectile->LaunchProjectile(this->LaunchSpeed);
			LastFireTime = FPlatformTime::Seconds();
		}
	}
}