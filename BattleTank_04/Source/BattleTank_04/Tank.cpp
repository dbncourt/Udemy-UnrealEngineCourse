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
	InputComponent->BindAction("Turret_CounterClockwise", EInputEvent::IE_Pressed, this, &ATank::RotateTurretCounterClockwise);
}

void ATank::RotateTurretCounterClockwise()
{
	this->Turret->SetRelativeRotation(FRotator(0.0f, -45.0f, 0.0f));
}

void ATank::RotateTurret()
{
	this->Turret->SetRelativeRotation(FRotator(0.0f, 45.0f, 0.0f));
}

void ATank::SetTurretChildActor(UChildActorComponent* Turret)
{
	UE_LOG(LogTemp, Warning, TEXT("SetTurretChildActor Called"));
	this->Turret = Turret;
}