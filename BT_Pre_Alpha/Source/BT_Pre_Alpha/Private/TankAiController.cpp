// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"

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

	UE_LOG(LogTemp, Warning, TEXT("AiTank is here"));
	AiPlyr = GetAiTank();

	if (!AiPlyr) { UE_LOG(LogTemp, Warning, TEXT("Ai Not Working")); return; }
	else { UE_LOG(LogTemp, Warning, TEXT("Ai is %s"), *(AiPlyr->GetName())); }

	AiEnemy = GetPlayerTank();
	if (!AiEnemy) { UE_LOG(LogTemp, Warning, TEXT("Ai Cant Find Enemy")); return; }
	else { UE_LOG(LogTemp, Warning, TEXT("Ai Found its Enemy : %s"), *(AiEnemy->GetName())); }

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
