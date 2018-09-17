#include "TankPlayerController.h"
#include "TankAimComponent.h"




void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	AimComp = GetPawn()->FindComponentByClass<UTankAimComponent>();
	if (!AimComp) { UE_LOG(LogTemp, Warning, TEXT("AimComp in TankPlayerController.cpp Not Working"));  return; }
	FoundAimComp(AimComp);
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardCH();
}

void ATankPlayerController::AimTowardCH()
{
	AimComp = GetPawn()->FindComponentByClass<UTankAimComponent>();
	if (!AimComp) { UE_LOG(LogTemp, Warning, TEXT("AimComp in TankPlayerController.cpp Not Working"));  return; }
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		AimComp->Aim(HitLocation);
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




