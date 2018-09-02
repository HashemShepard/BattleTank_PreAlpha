// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimComponent.h"
#include "TankBarrel.h"
// Sets default values for this component's properties
UTankAimComponent::UTankAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimComponent::SetBarrelRef(UTankBarrel* BarrelToSet) { Barrel = BarrelToSet; }

// Called when the game starts
void UTankAimComponent::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UTankAimComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTankAimComponent::AimAt(FVector AimLoc,float LaunchSpeed)
{
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("FiringPoint"));
	const FCollisionResponseParams  ResponseParam;
	const TArray < AActor * > ActorsToIgnore;

	if (UGameplayStatics::SuggestProjectileVelocity
	(this, OutLaunchVelocity, StartLocation, AimLoc,LaunchSpeed, false, 
	0.0F, 0.0F, ESuggestProjVelocityTraceOption::DoNotTrace, ResponseParam, ActorsToIgnore,true))
	{
		FVector AimDir = OutLaunchVelocity.GetSafeNormal();
		//UE_LOG(LogTemp, Warning, TEXT("%s Firing Direction : %s"), *(GetOwner()->GetName()),*(AimDir.ToString()));
		MoveBarrel(AimDir);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Target"));
	}
}


void UTankAimComponent::MoveBarrel(FVector AimDirection)
{
	FRotator CurrentBarrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator AimDirectionRotation = AimDirection.Rotation();
	FRotator DeltaRotation = AimDirectionRotation - CurrentBarrelRotation;
	Barrel->Elevate(DeltaRotation.Pitch);
}

