// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "TankAimComponent.h"

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto AiEnemy = GetWorld()->GetFirstPlayerController()->GetPawn();

	MoveToActor(AiEnemy,Acceptance);
	AimTowardPlayer();
}

void ATankAiController::AimTowardPlayer()
{
	auto AiEnemy = GetWorld()->GetFirstPlayerController()->GetPawn();
	AiPlyrAim = GetPawn()->FindComponentByClass<UTankAimComponent>();
	if (AiEnemy)
	{
		FVector PlyrLoc = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
		AiPlyrAim->Aim(PlyrLoc);
		//AiPlyr->Fire();
	}
}
