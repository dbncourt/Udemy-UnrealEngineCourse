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
		UOpenDoor::OpenDoor();
	}
}

void UOpenDoor::OpenDoor()
{
	AActor* Owner = GetOwner();
	FRotator Rotation = FRotator(0.0f, this->OpenAngle, 0.0f);

	Owner->SetActorRotation(Rotation);
}