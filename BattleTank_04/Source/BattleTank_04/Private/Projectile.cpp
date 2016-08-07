// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank_04.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
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
		LaunchBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
		LaunchBlast->bAutoActivate = true;
	}

	ImpactBlast = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ImpactBlast"));
	if (ensure(ImpactBlast))
	{
		ImpactBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
		ImpactBlast->bAutoActivate = false;
	}
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	CollisionMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
}

void AProjectile::LaunchProjectile(float Speed)
{
	ProjectileMovementComponent->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	ProjectileMovementComponent->Activate(true);
}

void AProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	LaunchBlast->Deactivate();
	ImpactBlast->Activate(true);
}