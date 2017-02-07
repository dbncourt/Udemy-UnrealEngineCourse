// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds_05.h"
#include "ChooseNextWaypoint.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Log, TEXT("Custom Choose Next Waypoint"));
	return EBTNodeResult::Type::Succeeded;
}