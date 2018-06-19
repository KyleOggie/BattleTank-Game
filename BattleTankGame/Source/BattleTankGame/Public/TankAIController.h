// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Public/Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKGAME_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
	
private:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	ATank* GetControlledTank() const;
	
	ATank* GetPlayerTank() const;
};
