// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimComponent = CreateDefaultSubobject<UTankAimComponent>(FName("Aiming Component"));
}

void ATank::SetBarrelRef(UTankBarrel* BarrelToSet) { TankAimComponent->SetBarrelRef(BarrelToSet); }

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::Aim(FVector AimLoc)
{
	TankAimComponent->AimAt(AimLoc, LaunchSpeed);
}



