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

	this->LineReach = 100.0f;
	this->PhysicsHandle = nullptr;
	this->InputComponent = nullptr;
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UGrabber::FindPhysicsHandleComponent();
	UGrabber::SetupInputComponent();
}

#pragma region Begin Play Configuration
void UGrabber::FindPhysicsHandleComponent()
{
	this->PhysicsHandle = GetOwner()->FindComponentByClass <UPhysicsHandleComponent>();
	if (!this->PhysicsHandle)
	{
		UE_LOG(LogTemp, Error, TEXT("% Missing Physics Handle Component"), *GetOwner()->GetName());
	}
}

void UGrabber::SetupInputComponent()
{
	this->InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (!this->InputComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("% Missing Input Component"), *GetOwner()->GetName());
	}
	else
	{
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
}
#pragma endregion

// Called every frame
void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (this->PhysicsHandle->GrabbedComponent)
	{
		FVector Location;
		FRotator Rotation;
		GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(Location, Rotation);

		FVector LineTraceEnd = (Location + (Rotation.Vector() * this->LineReach));
		this->PhysicsHandle->SetTargetLocation(LineTraceEnd);
	}
}

const FHitResult UGrabber::GetFirstPhysicsBodyInReach()
{
	FVector Location;
	FRotator Rotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(Location, Rotation);

	FVector LineTraceEnd = (Location + (Rotation.Vector() * this->LineReach));

	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		Hit,
		Location,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		FCollisionQueryParams(FName(TEXT("")), false, GetOwner()));

	if (Hit.GetActor())
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *Hit.GetActor()->GetName());
	}
	return Hit;
}

void UGrabber::Grab()
{
	FHitResult Hit = UGrabber::GetFirstPhysicsBodyInReach();

	if (Hit.GetActor())
	{
		UE_LOG(LogTemp, Warning, TEXT("Grabbing: %s"), *Hit.GetActor()->GetName());

		this->PhysicsHandle->GrabComponent(
			Hit.GetComponent(),
			EName::NAME_None,
			Hit.GetComponent()->GetOwner()->GetActorLocation(),
			true);
	}
}

void UGrabber::Release()
{
	UE_LOG(LogTemp, Warning, TEXT("Releasing!!"));
	this->PhysicsHandle->ReleaseComponent();
}