// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_04_API ATank : public APawn
{
	GENERATED_BODY()

public:
	ATank ();

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth;
};