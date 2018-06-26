// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Tank.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	auto TankName = GetName();


}


// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay(); // Needed for Blueprint Beginplay to run!

}


float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamageAmount, 0, CurrentHealth);

	UE_LOG(LogTemp, Warning, TEXT("DamageAmount = %f, DamageToApply = %f"), DamageAmount, DamageToApply);

	return DamageToApply;
}

