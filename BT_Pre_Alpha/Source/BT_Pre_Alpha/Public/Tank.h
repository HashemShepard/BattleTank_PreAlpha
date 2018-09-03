// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"
class UTankBarrel; class UTank_Turret;
class UTankAimComponent;
UCLASS()
class BT_PRE_ALPHA_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	void Aim(FVector AimLoc);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Fire();

	UFUNCTION(BlueprintCallable,Category=Setup)
	void SetBarrelRef(UTankBarrel* BarrelToSet);
	
	UFUNCTION(BlueprintCallable,Category = Setup)
	void SetTurretRef(UTank_Turret* TurretToSet);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UTankAimComponent* TankAimComponent = nullptr;

public:	
	// Called every frame

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	
private:
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 100000.0;
	
};
