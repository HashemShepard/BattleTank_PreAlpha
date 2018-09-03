// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	auto ElevationChange = FMath::Clamp<float>(RelativeSpeed, -1, 1) * MaxDegsPerSec * GetWorld()->DeltaTimeSeconds;
	auto NewElevation = RelativeRotation.Pitch + ElevationChange;
	SetRelativeRotation(FRotator(FMath::Clamp<float>(NewElevation,MinElev,MaxElev), 0, 0));
}



