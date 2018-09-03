// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank_Turret.h"


void UTank_Turret::TurretRotate(float RelativeSpeed)
{
	auto RotChange = FMath::Clamp<float>(RelativeSpeed, -1, 1) * MaxDegsPerSec * GetWorld()->DeltaTimeSeconds;
	auto NewRot = RelativeRotation.Yaw + RotChange;
	SetRelativeRotation(FRotator(0, NewRot, 0));
}

