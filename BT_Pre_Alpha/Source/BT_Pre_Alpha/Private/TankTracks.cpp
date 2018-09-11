// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"


void UTankTracks::Throttling(float Throttle)
{
	FVector ForceApplied = GetForwardVector()*Throttle*MaxDrivingForce;
	FVector ForceLocation = GetComponentLocation();
	UPrimitiveComponent* TankBody = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankBody->AddForceAtLocation(ForceApplied, ForceLocation);
}
