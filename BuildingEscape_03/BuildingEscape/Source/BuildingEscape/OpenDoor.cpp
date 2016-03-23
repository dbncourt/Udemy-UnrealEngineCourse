#include "BuildingEscape.h"
#include "OpenDoor.h"

UOpenDoor::UOpenDoor()
{
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	this->CloseDelay = 1.0f;
	this->TimeLastOpen = 0.0f;
}

void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
}

void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

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
	
	UE_LOG(LogTemp, Warning, TEXT("Total Mass is: %f"), TotalMass);
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