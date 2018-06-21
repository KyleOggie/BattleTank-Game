// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void  UTankBarrel::Elevate(float DegreesPerSecond)
{
	// Then will need to move barrel right amount this frame
	// Given max elevation speed, and relative frame time
	UE_LOG(LogTemp, Warning, TEXT("Barrel-Elevate() called at speed %f"), DegreesPerSecond);
}


