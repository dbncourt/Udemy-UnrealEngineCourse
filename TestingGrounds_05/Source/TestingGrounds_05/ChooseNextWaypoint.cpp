// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds_05.h"
#include "ChooseNextWaypoint.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PatrollingGuard.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	APatrollingGuard* patrollingGuard = Cast<APatrollingGuard>(OwnerComp.GetAIOwner()->GetPawn());
	TArray<AActor*> patrollingPoints = patrollingGuard->GetPatrollingPoints();

	UBlackboardComponent* blackboard = OwnerComp.GetBlackboardComponent();
	int32 index = blackboard->GetValueAsInt(IndexKey.SelectedKeyName);

	if (patrollingPoints.Num() > 0)
	{
		if (++index == patrollingPoints.Num())
		{
			index = 0;
		}

		blackboard->SetValueAsInt(IndexKey.SelectedKeyName, index);
		blackboard->SetValueAsObject(WaypointKey.SelectedKeyName, patrollingPoints[index]);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No patrolling points found"));
	}

	return EBTNodeResult::Type::Succeeded;
}