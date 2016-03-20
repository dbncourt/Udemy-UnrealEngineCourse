// You can do whatever you want with this! :)

#include "BuildingEscape.h"
#include "OpenDoor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	this->CloseDelay = 1.0f;
	this->TimeLastOpen = 0.0f;
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	this->Triggerer = GetWorld()->GetFirstPlayerController()->GetPawn();
}

// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (this->PressurePlate->IsOverlappingActor(this->Triggerer))
	{
		UOpenDoor::Open();
		this->TimeLastOpen = GetWorld()->GetTimeSeconds();
	}
	else if (GetWorld()->GetTimeSeconds() - this->TimeLastOpen > this->CloseDelay)
	{
		UOpenDoor::Close();
	}
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