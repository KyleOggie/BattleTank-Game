// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	OnComponentHit;
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}


void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpusle, const FHitResult& Hit)
{
	// Drive the tracks
	DriveTrack();
	// Apply sideways force
	ApplySidewaysForce();
	// Reset throttle
	CurrentThrottle = 0;
}



void UTankTrack::ApplySidewaysForce()
{
	// Calculate the SpliSpeed
	auto SlipSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	// Work out the required accelaration this frame to correct
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAcceleration = -SlipSpeed / DeltaTime * GetRightVector();
	// Calculate and apply sideways force (F= m a)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; // Devide by 2 for both tracks

	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::SetThrottle(float Throttle)
{
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1, 1);

}

void UTankTrack::DriveTrack()
{ 
auto FoceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
auto ForceLocation = GetComponentLocation();
auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

TankRoot->AddForceAtLocation(FoceApplied, ForceLocation);
}