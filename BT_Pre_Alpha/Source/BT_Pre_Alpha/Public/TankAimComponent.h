// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Engine/World.h" 
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "TankAimComponent.generated.h"
UENUM()
enum class EFiringStatus : uint8
{
	Reloading,
	Aiming,
	TargetLocked
};
class UTankBarrel; class UTank_Turret;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BT_PRE_ALPHA_API UTankAimComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void intializeAim(UTankBarrel* BarrelToSet, UTank_Turret* TurretToSet);

	// Sets default values for this component's properties
	UTankAimComponent();
	void AimAt(FVector AimLoc,float LaunchSpeed);
	

	UPROPERTY(BlueprintReadOnly)
	EFiringStatus FiringStatus = EFiringStatus::Aiming;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UTankBarrel* Barrel=nullptr;
	UTank_Turret* Turret = nullptr;
	void MoveBarrelTurret(FVector AimDirection);
};
