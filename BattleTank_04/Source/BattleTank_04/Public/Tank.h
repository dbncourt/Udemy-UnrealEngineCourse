// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_04_API ATank : public APawn
{
	GENERATED_BODY()

public:
	ATank();

	void AimAt(FVector AimLocation);

	UFUNCTION(BlueprintCallable, Category = "SetUp")
	void SetBarrelReference(UStaticMeshComponent* Barrel);

protected:
	UTankAimingComponent* TankAimingComponent;

private:
	virtual void BeginPlay() override;
	
	virtual void Tick( float DeltaTime ) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;	

	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed;
};
