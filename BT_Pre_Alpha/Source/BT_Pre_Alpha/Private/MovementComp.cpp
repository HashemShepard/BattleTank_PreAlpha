// Fill out your copyright notice in the Description page of Project Settings.

#include "MovementComp.h"
#include "TankTracks.h"

void UMovementComp::intialize(UTankTracks * LTankTracksToSet, UTankTracks * RTankTracksToSet)
{
	if (!LTankTracksToSet || !RTankTracksToSet) { return; }
	LTankTracks = LTankTracksToSet;
	RTankTracks = RTankTracksToSet;
}

void UMovementComp::OnWard(float POWER)
{
	if (!LTankTracks || !RTankTracks) { return; }
	LTankTracks->Throttling(POWER);
	RTankTracks->Throttling(POWER);
}

void UMovementComp::IntendTurnRight(float POWER)
{
	if (!LTankTracks || !RTankTracks) { return; }
	LTankTracks->Throttling(POWER);
	RTankTracks->Throttling(-POWER);

}

void UMovementComp::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	OnWard(ForwardThrow+0.25);

	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntendTurnRight(RightThrow+0.25);
	
}
