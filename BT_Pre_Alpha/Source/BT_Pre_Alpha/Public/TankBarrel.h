// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "TankBarrel.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent))
class BT_PRE_ALPHA_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	//between -1 and 1 (clamping)
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere,Category = Setup)
		float MaxDegsPerSec = 5.0;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElev = 35.0;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElev = 0;

	
};
