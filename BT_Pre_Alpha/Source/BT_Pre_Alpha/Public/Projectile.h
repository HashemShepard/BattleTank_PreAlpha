// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"
#include "Public/TimerManager.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"
UCLASS()
class BT_PRE_ALPHA_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();
	UProjectileMovementComponent* ProjectileMovementComponent = nullptr;

	virtual void Tick(float DeltaTime) override;
	void Launch(float speed);

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float DestoryDelay = 0.1;
	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float BaseDamage = 20;
	UPROPERTY(VisibleAnywhere, Category = Firing)
		UStaticMeshComponent* CollisionMesh=nullptr;
	UPROPERTY(VisibleAnywhere, Category = Firing)
		UParticleSystemComponent* LaunchBlast = nullptr;
	UPROPERTY(VisibleAnywhere, Category = Firing)
		UParticleSystemComponent* ImpactBlast = nullptr;
	UPROPERTY(VisibleAnywhere, Category = Firing)
		URadialForceComponent* ExplosionForce = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	void OnExpire();

};
