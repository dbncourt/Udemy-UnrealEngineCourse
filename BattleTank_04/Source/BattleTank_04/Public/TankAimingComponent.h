// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_04_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTankAimingComponent();

	void AimAt(FVector AimLocation, float LaunchSpeed);

	void SetBarrelReference(class UTankBarrel* Barrel);
	class UTankBarrel* GetBarrelReference();

	void SetTurretReference(class UTankTurret* Turret);
	class UTankTurret* GetTurretReference();

private:
	void MoveBarrelTowards(FVector AimDirection);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState;

private:
	class UTankBarrel* Barrel;

	class UTankTurret* Turret;
};