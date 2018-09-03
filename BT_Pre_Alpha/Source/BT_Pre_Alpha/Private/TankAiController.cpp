// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "Tank.h"

ATank* ATankAiController::GetAiTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAiController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();

	AiPlyr = GetAiTank();
	if (!AiPlyr) { UE_LOG(LogTemp, Warning, TEXT("Ai Not Working")); return; }

	AiEnemy = GetPlayerTank();
	if (!AiEnemy) { UE_LOG(LogTemp, Warning, TEXT("Ai Cant Find Enemy")); return; }
}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardPlayer();
	
}

void ATankAiController::AimTowardPlayer()
{
	if (GetPlayerTank())
	{
		FVector PlyrLoc = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
		GetAiTank()->Aim(PlyrLoc);
	}
}
