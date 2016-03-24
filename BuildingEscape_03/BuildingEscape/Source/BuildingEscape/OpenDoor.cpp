#include "BuildingEscape.h"
#include "OpenDoor.h"

UOpenDoor::UOpenDoor()
{
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	this->CloseDelay = 1.0f;
	this->TimeLastOpen = 0.0f;
	this->PressurePlate = nullptr;
}

void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
}

void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (!this->PressurePlate)
	{
		GEngine->AddOnScreenDebugMessage(DEBUG_MESSAGE_ID, 1.0f, FColor::Red, TEXT("Missing Pressure Plate Reference for: ") + FString(*GetOwner()->GetName()));
		return;
	}
	if (UOpenDoor::GetTotalMassOnThePale() > 30.0f)
	{
		UOpenDoor::Open();
		this->TimeLastOpen = GetWorld()->GetTimeSeconds();
	}
	else if (GetWorld()->GetTimeSeconds() - this->TimeLastOpen > this->CloseDelay)
	{
		UOpenDoor::Close();
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

void UOpenDoor::Open()
{
	FRotator Rotation = FRotator(0.0f, this->OpenAngle, 0.0f);
	Rotate(Rotation);
}

void UOpenDoor::Close()
{
	FRotator Rotation = FRotator(0.0f, 0.0f, 0.0f);
	Rotate(Rotation);
}

void UOpenDoor::Rotate(FRotator Rotation)
{
	GetOwner()->SetActorRotation(Rotation);
}