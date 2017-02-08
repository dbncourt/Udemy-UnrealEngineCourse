// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds_05.h"
#include "PatrolRouteComponent.h"

UPatrolRouteComponent::UPatrolRouteComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UPatrolRouteComponent::BeginPlay()
{
	Super::BeginPlay();
}

TArray<AActor*> const UPatrolRouteComponent::GetPatrollingPoints() const
{
	return this->PatrollingPoints;
}

