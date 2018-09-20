// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include"GameFramework/Actor.h"
#include "Tank.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);
UCLASS()
class BT_PRE_ALPHA_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	virtual float TakeDamage	(float DamageAmount,struct FDamageEvent const & DamageEvent,class AController * EventInstigator,AActor * DamageCauser)override;
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		int32 IntialHealth = 100;
	int32 CurrentHealth;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Setup")
		float GetHealthPercent() const;

	FTankDelegate OnTankDeath;
	

};
