#include "BuildingEscape.h"
#include "Grabber.h"

UGrabber::UGrabber()
{
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	this->LineReach = 100.0f;
	this->PhysicsHandle = nullptr;
	this->InputComponent = nullptr;
}

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

void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (this->PhysicsHandle->GrabbedComponent)
	{
		this->PhysicsHandle->SetTargetLocation(UGrabber::GetReachLineEnd());
	}
}

FVector UGrabber::GetReachLineStart()
{
	FVector Location;
	FRotator Rotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(Location, Rotation);

	return Location;
}

FVector UGrabber::GetReachLineEnd()
{
	FVector Location;
	FRotator Rotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(Location, Rotation);

	return (Location + (Rotation.Vector() * this->LineReach));
}

const FHitResult UGrabber::GetFirstPhysicsBodyInReach()
{
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		Hit,
		UGrabber::GetReachLineStart(),
		UGrabber::GetReachLineEnd(),
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
		this->PhysicsHandle->GrabComponent(
			Hit.GetComponent(),
			EName::NAME_None,
			Hit.GetComponent()->GetOwner()->GetActorLocation(),
			true);
	}
}

void UGrabber::Release()
{
	this->PhysicsHandle->ReleaseComponent();
}