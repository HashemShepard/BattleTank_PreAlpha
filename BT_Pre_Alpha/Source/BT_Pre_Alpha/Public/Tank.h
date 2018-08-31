// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "TankAimComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BT_PRE_ALPHA_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	void Aim(FVector AimLoc);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UTankAimComponent* TankAimComponent = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	
private:
	
	
};
