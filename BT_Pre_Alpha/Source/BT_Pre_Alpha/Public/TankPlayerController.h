// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Runtime/Engine/Public/CollisionQueryParams.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"
class ATank;

/**
 * 
 */
UCLASS()
class BT_PRE_ALPHA_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

private:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void AimTowardCH();
	bool GetSightRayHitLocation(FVector &Hit) const;
	bool GetLookDir(FVector2D CrosshairLOC, FVector &WorldLoc, FVector &WorldDir) const;
	bool GetVectorHitLoc(FVector LookDir, FVector &HitLocation) const;
	float LineTraceRange = 1000000.0;

	ATank* plyr1 = nullptr;
	UPROPERTY(EditAnywhere)
	float CrosshairXLoc=0.5;
	UPROPERTY(EditAnywhere)
	float CrosshairYLoc=1.0/3.0;

	
};
