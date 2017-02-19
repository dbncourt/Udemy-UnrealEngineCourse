// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds_05.h"
#include "ChooseNextWaypoint.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PatrolRouteComponent.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type response;
	const APawn* pawn = OwnerComp.GetAIOwner()->GetPawn();
	const UPatrolRouteComponent* patrolRouteComponent = Cast<UPatrolRouteComponent>(pawn->GetComponentByClass(UPatrolRouteComponent::StaticClass()));
	if (ensure(patrolRouteComponent))
	{
		const TArray<AActor*> patrollingPoints = patrolRouteComponent->GetPatrollingPoints();

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
			response = EBTNodeResult::Type::Succeeded;
		}
		else
		{
			response = EBTNodeResult::Failed;
		}
	}
	else
	{
		response = EBTNodeResult::Aborted;
	}
	
	return response;
}