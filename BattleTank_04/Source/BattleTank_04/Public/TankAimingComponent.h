// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked,
	NoAmmo
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_04_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTankAimingComponent();

	void AimAt(FVector AimLocation);

	UFUNCTION(BlueprintCallable, Category = "SetUp")
	void Initialize(class UTankBarrel* Barrel, class UTankTurret* Turret);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Firing")
	int32 GetAmmoAmount() const;

	EFiringState GetFiringState();

private:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	
	virtual void BeginPlay() override;

	void MoveBarrelTowards(FVector AimDirection);

	bool IsBarrelMoving();

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState;

private:
	class UTankBarrel* Barrel;

	class UTankTurret* Turret;

	UPROPERTY(EditDefaultsOnly, Category = "SetUp")
	TSubclassOf<class AProjectile> Projectile;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	double ReloadTime;

	double LastFireTime;

	FVector LastForwardVector;

	FVector AimDirection;

	int32 Ammo;
};