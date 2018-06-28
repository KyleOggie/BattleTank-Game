// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

// Forward Declarations
class ASprungWheel;

/**
 *  Tank Track is used to set maximum driving force, and to apply forces
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKGAME_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public: 
	// Sets a throttle between -1 and +1 - found in project settings
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	// Max force per track in Newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 40000000; // Assume 40 tonne tank, and 1g acceletation = 4 hundred thousand Newtons force
	
private:
	UTankTrack();

	TArray<ASprungWheel*> GetWheels() const;

	void DriveTrack(float CurrentThrottle);

};
