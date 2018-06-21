// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "public/TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new include above

class UTankBarrel; // Forward Declaration

UCLASS()
class BATTLETANKGAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

protected:
	UTankAimingComponent * TankAimingComponent = nullptr;


private:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Sets default values for this pawn's properties
	ATank();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000; // TODO Find sensible starting value Tank.h
	

};
