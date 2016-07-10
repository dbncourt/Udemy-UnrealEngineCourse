// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_04_API ATank : public APawn
{
	GENERATED_BODY()

public:
	ATank();

	void AimAt(FVector AimLocation);

	UFUNCTION(BlueprintCallable, Category = "SetUp")
	void SetBarrelReference(class UTankBarrel* Barrel);

	UFUNCTION(BlueprintCallable, Category = "SetUp")
	void SetTurretReference(class UTankTurret* Turret);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

protected:
	class UTankAimingComponent* TankAimingComponent;

private:
	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = "SetUp")
	TSubclassOf<class AProjectile> Projectile;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	double ReloadTime;
	
	double LastFireTime;
};