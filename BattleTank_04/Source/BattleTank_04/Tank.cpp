// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank_04.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	UE_LOG(LogTemp, Warning, TEXT("SetupPlayerInputComponent Called"));

	InputComponent->BindAction("Turret_Clockwise", EInputEvent::IE_Pressed, this, &ATank::RotateTurret);
}

void ATank::RotateTurret()
{
	UE_LOG(LogTemp, Warning, TEXT("RotateTurret Called"));
}