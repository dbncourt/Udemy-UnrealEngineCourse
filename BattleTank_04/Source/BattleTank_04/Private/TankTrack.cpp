// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank_04.h"
#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
	UPrimitiveComponent::SetNotifyRigidBodyCollision(true);

	CurrentThrottle = 0.0f;
}

void UTankTrack::SetThrottle(float Throttle)
{
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1.0f, 1.0f);
}

void UTankTrack::DriveTrack()
{
	FVector ForceApplied = (GetForwardVector() * CurrentThrottle) * TrackMaxDrivingForce;
	FVector ForceLocation = GetComponentLocation();

	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

void UTankTrack::BeginPlay()
{
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::ApplySidewaysForce()
{
	float DeltaTime = GetWorld()->GetDeltaSeconds();
	float SlippageSpeed = FVector::DotProduct(this->ComponentVelocity, GetRightVector());
	FVector CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	UStaticMeshComponent* TankRoot = Cast<UStaticMeshComponent>(this->GetOwner()->GetRootComponent());
	FVector CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2;

	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	DriveTrack();
	ApplySidewaysForce();
	CurrentThrottle = 0.0f;
}