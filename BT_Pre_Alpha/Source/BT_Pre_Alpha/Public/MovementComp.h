// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "MovementComp.generated.h"
class UTankTracks;
/**
* Responsible for driving the tank tracks
*/
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BT_PRE_ALPHA_API UMovementComp : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void intialize(UTankTracks* LeftTrackToSet, UTankTracks* RightTrackToSet);

	UFUNCTION(BlueprintCallable, Category = "Input")
		void OnWard(float POWER);

	UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendTurnRight(float POWER);

private:
	// Called from the pathfinding logic by the AI controllers
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

	UTankTracks* LTankTracks = nullptr;
	UTankTracks* RTankTracks = nullptr;
};

