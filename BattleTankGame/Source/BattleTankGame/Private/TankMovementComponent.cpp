// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "Public/TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	// TODO prevent double-speed, due to multiple inputs
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

}


void UTankMovementComponent::IntendTurnRight(float Throw)
{
	// TODO prevent double-speed, due to multiple inputs
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);

	UE_LOG(LogTemp, Warning, TEXT("Intend turn right throw: %f"), Throw);
}