// Fill out your copyright notice in the Description page of Project Settings.

#include "Mortar.h"


// Sets default values
AMortar::AMortar()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}
void AMortar::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = IntialHealth;
}

float AMortar::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	int32 Damage = (int32)DamageAmount;
	int32 DamageToApply = FMath::Clamp(Damage, 0, CurrentHealth);
	CurrentHealth -= DamageToApply;
	UE_LOG(LogTemp, Warning, TEXT("PERCENT : %f "), (float)CurrentHealth / (float)IntialHealth);
	if (CurrentHealth <= 0)
	{
		OnMortarDeath.Broadcast();
	}
	return DamageToApply;
}



float AMortar::GetHealthPercentMortar() const
{
	float PERCENT = (float)CurrentHealth / (float)IntialHealth;
	return PERCENT;
}
