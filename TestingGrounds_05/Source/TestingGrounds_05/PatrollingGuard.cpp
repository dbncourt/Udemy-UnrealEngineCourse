// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds_05.h"
#include "PatrollingGuard.h"

APatrollingGuard::APatrollingGuard()
{

}

APatrollingGuard::~APatrollingGuard()
{

}

TArray<AActor*> const APatrollingGuard::GetPatrollingPoints()
{
	return this->PatrollingPoints;
}