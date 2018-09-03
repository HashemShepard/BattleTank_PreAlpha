#pragma once
#include "Engine/World.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Tank_Turret.generated.h"
/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BT_PRE_ALPHA_API UTank_Turret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//between -1 and 1 (clamping)
	void TurretRotate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegsPerSec = 5.0;
	
	
	
};
