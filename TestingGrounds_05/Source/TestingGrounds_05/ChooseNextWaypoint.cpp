// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds_05.h"
#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* blackboard = OwnerComp.GetBlackboardComponent();
	int32 index = blackboard->GetValueAsInt(IndexKey.SelectedKeyName);

	UE_LOG(LogTemp, Log, TEXT("Waypoint index: %i"), index);
	return EBTNodeResult::Type::Succeeded;
}