#include "TankPlayerController.h"
#include "Tank.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	plyr1 = GetControlledTank();
	if (!plyr1) { UE_LOG(LogTemp, Warning, TEXT("TankPlayerController.cpp Not Working")); return; }
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
		GetControlledTank()->Aim(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D CrosshairLOC = FVector2D (ViewportSizeX*CrosshairXLoc, ViewportSizeY*CrosshairYLoc);
	FVector WorldLoc, LookDir;
	if (GetLookDir(CrosshairLOC, WorldLoc, LookDir))
	{
		GetVectorHitLoc(LookDir,HitLocation);
		return true;
	}
	return false;
}

bool ATankPlayerController::GetLookDir(FVector2D CrosshairLOC, FVector & WorldLoc, FVector & WorldDir) const
{
	return DeprojectScreenPositionToWorld(CrosshairLOC.X, CrosshairLOC.Y, WorldLoc, WorldDir);
}

bool ATankPlayerController::GetVectorHitLoc(FVector LookDir , FVector &HitLocation) const
{
	FHitResult Hitted;
	FVector Start = PlayerCameraManager->GetCameraLocation();
	FVector End = Start +(LookDir * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(Hitted, Start, End,ECollisionChannel::ECC_Visibility))
	{
		HitLocation = Hitted.Location;
		return true;
	}
	HitLocation = FVector(0.0);
	return false;
}




