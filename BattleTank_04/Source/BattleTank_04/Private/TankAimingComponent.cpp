// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank_04.h"
#include "TankAimingComponent.h"

UTankAimingComponent::UTankAimingComponent()
{
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
}

void UTankAimingComponent::AimAt(FVector AimLocation, float LaunchSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT("%s Aiming At %s from %s"), *GetOwner()->GetName(), *AimLocation.ToString(), *this->Barrel->GetComponentLocation().ToString());
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* Barrel)
{
	this->Barrel = Barrel;
}