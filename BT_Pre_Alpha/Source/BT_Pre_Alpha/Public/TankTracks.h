// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "TankTracks.generated.h"
/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BT_PRE_ALPHA_API UTankTracks : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Setup)
		void Throttling(float Throttle);

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxDrivingForce = 15000000.0;
	
	UTankTracks();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void AntiSlip();
	virtual void BeginPlay()override;
	float localThrottle=0.0;
	void DriveTank();
	
private:
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
