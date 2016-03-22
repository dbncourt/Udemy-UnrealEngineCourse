// You can do whatever you want with this! :)

#include "BuildingEscape.h"
#include "Grabber.h"


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	this->DebugLineReach = 100.0f;
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	FVector Location;
	FRotator Rotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(Location, Rotation);

	UE_LOG(LogTemp, Warning, TEXT("Location: %s - Rotation: %s"), *Location.ToString(), *Rotation.ToString());

	DrawDebugLine(GetWorld(),
		Location,
		(Location + (Rotation.Vector() * this->DebugLineReach)),
		FColor(0, 255, 0),
		false,
		0.0f,
		0.0f,
		10.0f
		);
}

