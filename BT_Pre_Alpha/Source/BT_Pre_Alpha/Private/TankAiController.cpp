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
	auto AiPlyr = GetPawn()->FindComponentByClass<UTankAimComponent>();

	if (AiEnemy)
	{
		MoveToActor(AiEnemy, Acceptance);
		FVector PlyrLoc = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
		AiPlyr->Aim(PlyrLoc);
		AiPlyr->Fire();	
	}
}

