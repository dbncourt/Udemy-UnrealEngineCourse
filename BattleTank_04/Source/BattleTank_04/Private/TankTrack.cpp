// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank_04.h"
#include "TankTrack.h"

UTankTrack::UTankTrack()
{
}

void UTankTrack::SetThrottle(float Throttle)
{
	UE_LOG(LogTemp, Warning, TEXT("%s Throttle: %f"), *GetName(), Throttle);
}