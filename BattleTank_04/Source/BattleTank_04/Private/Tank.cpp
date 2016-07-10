// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank_04.h"
#include "../Public/Tank.h"
#include "../Public/TankBarrel.h"
#include "../Public/TankTurret.h"
#include "../Public/Projectile.h"
#include "../Public/TankAimingComponent.h"

// Sets default values
ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;

	this->TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(TEXT("Aiming Component"));
	this->LaunchSpeed = 4000.0f;
	this->LastFireTime = 0.0;
	this->ReloadTime = 3.0;
}

void ATank::AimAt(FVector AimLocation)
{
	this->TankAimingComponent->AimAt(AimLocation, this->LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel * Barrel)
{
	this->TankAimingComponent->SetBarrelReference(Barrel);
}

void ATank::SetTurretReference(class UTankTurret* Turret)
{
	this->TankAimingComponent->SetTurretReference(Turret);
}

void ATank::Fire()
{
	bool IsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTime;

	if (IsReloaded)
	{
		UTankBarrel* Barrel = this->TankAimingComponent->GetBarrelReference();
		if (Barrel && this->Projectile)
		{
			FVector ProjectileLocation = Barrel->GetSocketLocation(FName("Cannon"));
			FRotator ProjectileRotation = Barrel->GetSocketRotation(FName("Cannon"));
			AProjectile* SpawnedProjectile = GetWorld()->SpawnActor<AProjectile>(this->Projectile, ProjectileLocation, ProjectileRotation);
			SpawnedProjectile->LaunchProjectile(this->LaunchSpeed);

			LastFireTime = FPlatformTime::Seconds();
		}
	}
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}