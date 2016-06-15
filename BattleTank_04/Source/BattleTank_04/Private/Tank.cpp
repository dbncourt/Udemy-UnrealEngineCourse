// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank_04.h"
#include "Tank.h"

// Sets default values
ATank::ATank()
{
	this->TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(TEXT("Aiming Component"));;

	PrimaryActorTick.bCanEverTick = true;
}

void ATank::AimAt(FVector AimLocation)
{
	this->TankAimingComponent->AimAt(AimLocation);
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}