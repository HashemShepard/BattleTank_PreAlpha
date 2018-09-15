// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"
class UTankBarrel; class UTank_Turret; class AProjectile; class UTankTracks;
class UTankAimComponent;  class UMovementComp;
UCLASS()
class BT_PRE_ALPHA_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	void Aim(FVector AimLoc);
	double LastFireTime = 0;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UFUNCTION(BlueprintCallable, Category = Setup)
		void Fire();
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelRef(UTankBarrel* BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretRef(UTank_Turret* TurretToSet);


	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 5000.0;
	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTime = 3;

	UPROPERTY(BlueprintReadOnly)
		UTankAimComponent* TankAimComponent = nullptr;
	

protected:
	virtual void BeginPlay() override;
	
private:
	
	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBP;

	//Local Reference for the barrel
	UTankBarrel* BarrelLocalRef = nullptr;
};
