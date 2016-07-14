// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_04_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATankPlayerController();

protected:
	UFUNCTION(BlueprintCallable, Category = "SetUp")
	class ATank* GetControlledTank() const;

private:
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	void AimTowardsCrosshair();
	
	bool GetSightRayHitLocation(_Out_ FVector &HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, _Out_ FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector& LookDirection, _Out_ FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation;
	
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange;
};