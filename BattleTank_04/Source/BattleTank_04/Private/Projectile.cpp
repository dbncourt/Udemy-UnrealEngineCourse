// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank_04.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
	if (ensure(ProjectileMovementComponent))
	{
		ProjectileMovementComponent->bAutoActivate = false;
	}

	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Collision Mesh"));
	if (ensure(CollisionMesh))
	{
		SetRootComponent(CollisionMesh);
		CollisionMesh->SetNotifyRigidBodyCollision(true);
		CollisionMesh->SetVisibility(false);
	}

	LaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("LaunchBlast"));
	if (ensure(LaunchBlast))
	{
		LaunchBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
		LaunchBlast->bAutoActivate = true;
	}
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AProjectile::LaunchProjectile(float Speed)
{
	ProjectileMovementComponent->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	ProjectileMovementComponent->Activate(true);
}