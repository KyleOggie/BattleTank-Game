// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Tank.h"

//UE_LOG(LogTemp, Warning, TEXT("PlayerController can't find aiming component at BeginPlay "));

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




