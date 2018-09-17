// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "TankTracks.h"
// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::Fire()
{
	if (!BarrelLocalRef) { UE_LOG(LogTemp, Warning, TEXT("Error in Fire Tank.Cpp")); return; }
	if ((FPlatformTime::Seconds() - LastFireTime) > ReloadTime)
	{
		FVector FiringPoint = BarrelLocalRef->GetSocketLocation(FName("FiringPoint"));
		FRotator FiringRotation = BarrelLocalRef->GetSocketRotation(FName("FiringPoint"));
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBP, FiringPoint, FiringRotation);
	    Projectile->Launch(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}
	





