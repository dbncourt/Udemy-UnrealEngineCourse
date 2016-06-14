// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "Tank.h"
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

private:
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;	

	void AimTowardsCrosshair();
	
	bool GetSightRayHitLocation(_Out_ FVector &HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, _Out_ FVector& LookDirection) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation;
};
