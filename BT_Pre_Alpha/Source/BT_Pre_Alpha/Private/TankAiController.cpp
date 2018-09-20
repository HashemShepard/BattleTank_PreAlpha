// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "TankAimComponent.h"
#include "Tank.h"


void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAiController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }
		PossessedTank->OnTankDeath.AddUniqueDynamic(this, &ATankAiController::OnAiTankDeath);
	}
}

void ATankAiController::OnAiTankDeath()
{
	if (!GetPawn()) { return; }
	GetPawn()->DetachFromControllerPendingDestroy();
}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto AiEnemy = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AiPlyr = GetPawn()->FindComponentByClass<UTankAimComponent>();
	if (!AiPlyr|| !AiEnemy) { return; }
	if (AiEnemy)
	{
		MoveToActor(AiEnemy, Acceptance);
		FVector PlyrLoc = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
		AiPlyr->Aim(PlyrLoc);
		AiPlyr->Fire();	
	}
}

