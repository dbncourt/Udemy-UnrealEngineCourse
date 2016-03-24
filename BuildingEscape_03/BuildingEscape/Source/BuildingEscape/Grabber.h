#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

public:
	const static int DEBUG_MESSAGE_ID = 0;

private:
	void SetupInputComponent();
	void FindPhysicsHandleComponent();

	const FHitResult GetFirstPhysicsBodyInReach();
	
	FVector GetReachLineStart();
	FVector GetReachLineEnd();

	void Grab();
	void Release();
		
private:
	UPROPERTY(EditAnywhere)
	float LineReach;

	UPhysicsHandleComponent* PhysicsHandle;
	UInputComponent* InputComponent;
};
