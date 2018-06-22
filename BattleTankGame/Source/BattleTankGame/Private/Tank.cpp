// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Tank.h"
#include "Public/TankBarrel.h"
#include "Public/Projectile.h"
#include "Public/TankAimingComponent.h"
#include "Public/TankMovementComponent.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Yeet: Tank C++ Construct "), *TankName);

}


// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay(); // Needed for Blueprint Beginplay to run!
	
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Yeet: Tank C++ BeginPlay "), *TankName);

}


void ATank::Fire()
{

	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (Barrel && isReloaded) 
	{
		
		// Spawn a projectile at the socket location on the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>
			(ProjectileBlueprint,
				Barrel->GetSocketLocation(FName("Projectile")),
				Barrel->GetSocketRotation(FName("Projectile"))
				);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();

	}
}


void ATank::AimAt(FVector HitLocation)
{
	if (!TankAimingComponent) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);

}

