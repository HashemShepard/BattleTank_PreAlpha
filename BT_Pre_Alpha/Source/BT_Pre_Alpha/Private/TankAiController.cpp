// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "Tank.h"

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();

	AiPlyr = Cast<ATank>(GetPawn());
	if (!AiPlyr) { UE_LOG(LogTemp, Warning, TEXT("Ai Not Working")); return; }
	AiEnemy = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!AiEnemy) { UE_LOG(LogTemp, Warning, TEXT("Ai Cant Find Enemy")); return; }
}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AiEnemy = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	MoveToActor(AiEnemy,Acceptance);
	AimTowardPlayer();
}

void ATankAiController::AimTowardPlayer()
{
	AiEnemy = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (AiEnemy)
	{
		FVector PlyrLoc = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
		AiPlyr->Aim(PlyrLoc);
		AiPlyr->Fire();
	}
}
