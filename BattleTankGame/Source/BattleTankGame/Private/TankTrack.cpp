// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

#include "Public/SprungWheel.h"
#include "Public/SpawnPoint.h"

UTankTrack::UTankTrack()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

}


void UTankTrack::SetThrottle(float Throttle)
{
	float CurrentThrottle = FMath::Clamp<float>(Throttle, -1, 1);
	// Drive the tracks
	DriveTrack(CurrentThrottle);

}

void UTankTrack::DriveTrack(float CurrentThrottle)
{ 
	auto ForceApplied = CurrentThrottle * TrackMaxDrivingForce;
	auto Wheels = GetWheels();
	auto ForcePerWheel = ForceApplied / Wheel.Num();

	for (ASprungWheel* Wheel : Wheel)
	{
		Wheel->AddDrivingForce(ForcePerWheel);
	}
}

TArray<ASprungWheel*> UTankTrack::GetWheels() const
{
	TArray<ASprungWheel*> ResultArray;
	TArray<USceneComponent*> Children;
	GetChildrenComponents(true, Children);
	for (USceneComponent* Child : Children)
	{
		auto SpawnPointChild = Cast<USpawnPoint>(Child);
		if (!SpawnPointChild) continue;

		AActor* SpawnChild = SpawnPointChild->GetSpawnActor();
		auto SprungWheel = Cast<ASprungWheel>(SpawnChild);
		if (!SprungWheel) continue;

		ResultArray.Add(SprungWheel);
	}
	return ResultArray;
}