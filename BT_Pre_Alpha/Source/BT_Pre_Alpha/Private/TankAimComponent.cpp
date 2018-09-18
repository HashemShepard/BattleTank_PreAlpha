// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimComponent.h"
#include "TankBarrel.h"
#include "Tank_Turret.h"
#include "Projectile.h"


// Sets default values for this component's properties
UTankAimComponent::UTankAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
//	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimComponent::intializeAim(UTankBarrel* BarrelToSet, UTank_Turret* TurretToSet)
{
	if (!BarrelToSet || !TurretToSet) { return; }
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

// Called when the game starts
void UTankAimComponent::BeginPlay()
{
	Super::BeginPlay();
	
	LastFireTime = FPlatformTime::Seconds();
}

// Called every frame
void UTankAimComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (PlyrAmmo <= 0)
		FiringStatus = EFiringStatus::OutofAmmo;
	else if ((FPlatformTime::Seconds() - LastFireTime) < ReloadTime)
		FiringStatus = EFiringStatus::Reloading;
	else if (isBarrelMoving())
		FiringStatus = EFiringStatus::Aiming;
	else
		FiringStatus = EFiringStatus::TargetLocked;
}

int UTankAimComponent::GetAmmoLeft()
{
	return PlyrAmmo;
}

EFiringStatus UTankAimComponent::GetEFiringStatus()
{
	return FiringStatus;
}

void UTankAimComponent::Aim(FVector AimLoc)
{
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("FiringPoint"));
	const FCollisionResponseParams  ResponseParam;
	const TArray < AActor * > ActorsToIgnore;

	if (UGameplayStatics::SuggestProjectileVelocity
	(this, OutLaunchVelocity, StartLocation, AimLoc,LaunchSpeed, false, 
	0.0F, 0.0F, ESuggestProjVelocityTraceOption::DoNotTrace, ResponseParam, ActorsToIgnore,false))
	{
	    AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTurret(AimDirection);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Target"));
	}
}


void UTankAimComponent::MoveBarrelTurret(FVector AimDirection)
{
	if (!Barrel || !Turret) { return; }
	FRotator CurrentBarrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator AimDirectionRotation = AimDirection.Rotation();
	FRotator DeltaRotation = AimDirectionRotation - CurrentBarrelRotation;
	Barrel->Elevate(DeltaRotation.Pitch);
	if (DeltaRotation.Yaw > 180.0 || DeltaRotation.Yaw < -180)
		Turret->TurretRotate(-DeltaRotation.Yaw);
	else
		Turret->TurretRotate(DeltaRotation.Yaw);
}

bool UTankAimComponent::isBarrelMoving()
{
	FVector CurrentBarrelDir = Barrel->GetForwardVector();
	return CurrentBarrelDir.FVector::Equals(AimDirection, Tolerance);
}

void UTankAimComponent::Fire()
{
	if (!Barrel) { UE_LOG(LogTemp, Warning, TEXT("Error in Fire Tank.Cpp")); return; }
	if (FiringStatus==EFiringStatus::Aiming || FiringStatus == EFiringStatus::TargetLocked)
	{
		FVector FiringPoint = Barrel->GetSocketLocation(FName("FiringPoint"));
		FRotator FiringRotation = Barrel->GetSocketRotation(FName("FiringPoint"));
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(New_ProjectileBP, FiringPoint, FiringRotation);
		Projectile->Launch(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
		PlyrAmmo--;
	}
}

