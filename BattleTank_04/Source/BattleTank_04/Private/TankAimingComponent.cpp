// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank_04.h"
#include "../Public/TankBarrel.h"
#include "../Public/TankTurret.h"
#include "../Public/Projectile.h"
#include "../Public/TankAimingComponent.h"

UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	Barrel = nullptr;
	Turret = nullptr;
	FiringState = EFiringState::Reloading;

	LaunchSpeed = 4000.0f;
	ReloadTime = 3.0;
	Ammo = 3;
}

void UTankAimingComponent::BeginPlay()
{
	LastFireTime = FPlatformTime::Seconds();	
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	if (ensure(Barrel) && ensure(Turret))
	{
		FVector BarrelForwardVector = Barrel->GetForwardVector();
		FQuat RotationWithoutRoll = FQuat::FindBetweenVectors(BarrelForwardVector, AimDirection);

		FRotator DeltaRotator = RotationWithoutRoll.Rotator();
		if (DeltaRotator.Yaw >= 180)
		{
			DeltaRotator.Yaw = -DeltaRotator.Yaw;
		}
		
		Barrel->Elevate(DeltaRotator.Pitch);
		Turret->Rotate(DeltaRotator.Yaw);
	}
}

bool UTankAimingComponent::IsBarrelMoving()
{
	if (ensure(Barrel))
	{
		FVector CurrentForwardVector = Barrel->GetForwardVector();
		return !CurrentForwardVector.Equals(AimDirection, 0.1f);
	}
	else
	{
		return false;
	}
}

void UTankAimingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	if (Ammo == 0)
	{
		FiringState = EFiringState::NoAmmo; 
	}
	else if ((FPlatformTime::Seconds() - LastFireTime) < ReloadTime)
	{
		FiringState = EFiringState::Reloading;
	}
	else if (UTankAimingComponent::IsBarrelMoving())
	{
		FiringState = EFiringState::Aiming;
	}
	else
	{
		FiringState = EFiringState::Locked;
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
			AimDirection = LaunchVelocity.GetSafeNormal();
			UTankAimingComponent::MoveBarrelTowards(AimDirection);
		}
	}
}

void UTankAimingComponent::Initialize(class UTankBarrel* Barrel, class UTankTurret* Turret)
{
	this->Barrel = Barrel;
	if (ensure(Barrel))
	{
		LastForwardVector = Barrel->GetForwardVector().GetSafeNormal();
	}
	this->Turret = Turret;

}

void UTankAimingComponent::Fire()
{
	if (FiringState == EFiringState::Locked || FiringState == EFiringState::Aiming)
	{
		if (ensure(Projectile) && ensure(Barrel))
		{
			FVector ProjectileLocation = Barrel->GetSocketLocation("Cannon");
			FRotator ProjectileRotation = Barrel->GetSocketRotation("Cannon");

			AProjectile* SpawnedProjectile = GetWorld()->SpawnActor<AProjectile>(this->Projectile, ProjectileLocation, ProjectileRotation);
			SpawnedProjectile->LaunchProjectile(this->LaunchSpeed);
			LastFireTime = FPlatformTime::Seconds();
			--Ammo;
		}
	}
}

int32 UTankAimingComponent::GetAmmoAmount() const
{
	return Ammo;
}

EFiringState UTankAimingComponent::GetFiringState()
{
	return FiringState;
}