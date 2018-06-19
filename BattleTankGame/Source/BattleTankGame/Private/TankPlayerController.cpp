// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


// Called when the game starts or when spawned
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not controlling a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is controlling: %s"), *(ControlledTank->GetName()));
	}
	
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

