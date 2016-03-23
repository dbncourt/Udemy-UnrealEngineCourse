#include "BuildingEscape.h"
#include "PositionReporter.h"

UPositionReporter::UPositionReporter()
{
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UPositionReporter::BeginPlay()
{
	Super::BeginPlay();
	

	UE_LOG(LogTemp, Warning, TEXT("Owners Name is %s (%s)"), *GetOwner()->GetName(), *GetOwner()->GetTransform().GetTranslation().ToString());
	
}

void UPositionReporter::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
}

