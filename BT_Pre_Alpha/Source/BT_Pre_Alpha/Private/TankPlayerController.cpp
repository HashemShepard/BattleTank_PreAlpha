#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Tank is here"));
	plyr1 = GetControlledTank();

	if (!plyr1) { UE_LOG(LogTemp, Warning, TEXT("Not Working")); return; }
	else { UE_LOG(LogTemp, Warning, TEXT("player is %s"), *(plyr1->GetName())); }
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardCH();
}

void ATankPlayerController::AimTowardCH()
{
	if (!GetControlledTank()) { UE_LOG(LogTemp, Warning, TEXT("AimTowardCH Error")); return; }
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *(HitLocation.ToString()));
	}
	
	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D CrosshairLOC = FVector2D (ViewportSizeX*CrosshairXLoc, ViewportSizeY*CrosshairYLoc);
	HitLocation=FVector(CrosshairLOC, 0.0);
	return true;
}

