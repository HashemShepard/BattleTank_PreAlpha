// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "TankAimComponent.h"
#include "Tank.h"
#include"Mortar.h"




void ATankAiController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedMortar = Cast<AMortar>(InPawn);
		if (!ensure(PossessedMortar)) { return; }
		PossessedMortar->OnMortarDeath.AddUniqueDynamic(this, &ATankAiController::OnAiMortarDeath);
		UE_LOG(LogTemp, Warning, TEXT("MORTAR"));
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }
		PossessedTank->OnTankDeath.AddUniqueDynamic(this, &ATankAiController::OnAiTankDeath);
	}
}


void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAiController::OnAiTankDeath()
{
	if (!GetPawn()) { return; }
	GetPawn()->DetachFromControllerPendingDestroy();
}
void ATankAiController::OnAiMortarDeath()
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

