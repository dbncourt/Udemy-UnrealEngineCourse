// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank_04.h"
#include "../Public/Tank.h"
#include "../Public/TankBarrel.h"
#include "../Public/TankAimingComponent.h"

// Sets default values
ATank::ATank()
{
	this->TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(TEXT("Aiming Component"));
	this->LaunchSpeed = 100000;

	PrimaryActorTick.bCanEverTick = false;
}

void ATank::AimAt(FVector AimLocation)
{
	this->TankAimingComponent->AimAt(AimLocation, this->LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel * Barrel)
{
	this->TankAimingComponent->SetBarrelReference(Barrel);
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}