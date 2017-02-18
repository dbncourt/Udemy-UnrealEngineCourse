// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "PatrolRouteComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS_05_API UPatrolRouteComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPatrolRouteComponent();

	virtual void BeginPlay() override;
	
	TArray<AActor*> const GetPatrollingPoints() const;

private:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	TArray<AActor*> PatrollingPoints;
};