#include "BuildingEscape.h"
#include "OpenDoor.h"

UOpenDoor::UOpenDoor()
{
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	this->PressurePlate = nullptr;
	this->TriggerMass = 0.0f;
	this->InitialYaw = 0.0f;
}

void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	this->InitialYaw = this->GetOwner()->GetActorRotation().Yaw;
}

void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (!this->PressurePlate)
	{
		GEngine->AddOnScreenDebugMessage(DEBUG_MESSAGE_ID, 1.0f, FColor::Red, TEXT("Missing Pressure Plate Reference for: ") + FString(*GetOwner()->GetName()));
		return;
	}
	if (UOpenDoor::GetTotalMassOnThePale() > this->TriggerMass)
	{
		OnOpen.Broadcast();
	}
	else if(this->GetOwner()->GetActorRotation().Yaw > this->InitialYaw)
	{
		OnClose.Broadcast();
	}
}

float UOpenDoor::GetTotalMassOnThePale()
{
	float TotalMass = 0.0f;
	TArray<AActor*> Actors;
	this->PressurePlate->GetOverlappingActors(Actors);

	for (auto& Actor : Actors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}

	GEngine->AddOnScreenDebugMessage(DEBUG_MESSAGE_ID, 1.0f, FColor::Green, TEXT("Total Mass is: ") + FString::SanitizeFloat(TotalMass));
	return TotalMass;
}