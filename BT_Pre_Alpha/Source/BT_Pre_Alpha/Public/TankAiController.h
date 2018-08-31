#pragma once
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAiController.generated.h"

/**
 * 
 */
UCLASS()
class BT_PRE_ALPHA_API ATankAiController : public AAIController
{
	GENERATED_BODY()
	
public:
	

private:
	ATank* GetAiTank() const;
	ATank* GetPlayerTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void AimTowardPlayer();
	
	
	ATank* AiPlyr = nullptr;
	ATank* AiEnemy = nullptr;
};

