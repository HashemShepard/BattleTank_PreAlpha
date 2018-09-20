#pragma once
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAiController.generated.h"

class UTankAimComponent;
/**
 * 
 */
UCLASS()
class BT_PRE_ALPHA_API ATankAiController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void SetPawn(APawn* InPawn) override;


	UFUNCTION()
		void OnAiTankDeath();

	UFUNCTION()
		void OnAiMortarDeath();

private:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditDefaultsOnly, Category = "Firing" )
		float Acceptance = 1500.0;
};
