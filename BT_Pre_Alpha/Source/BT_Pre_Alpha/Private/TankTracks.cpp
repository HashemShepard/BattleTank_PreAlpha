// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"

UTankTracks::UTankTracks()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankTracks::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTankTracks::BeginPlay()
{
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTankTracks::OnHit);

}



void UTankTracks::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	DriveTank();
	AntiSlip();
	localThrottle = 0.0;
}

void UTankTracks::Throttling(float Throttle)
{
	localThrottle += Throttle;
}

void UTankTracks::DriveTank()
{
	FVector ForceApplied = GetForwardVector()*localThrottle*MaxDrivingForce;
	FVector ForceLocation = GetComponentLocation();
	UPrimitiveComponent* TankBody = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankBody->AddForceAtLocation(ForceApplied, ForceLocation);
}
void UTankTracks::AntiSlip()
{
	float DeltaTime = GetWorld()->GetDeltaSeconds();
	float slippage = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	FVector acceleration = slippage / DeltaTime *GetRightVector();
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	float mass = TankRoot->GetMass();
	FVector ReqForce = -(mass * acceleration) / 2;
	TankRoot->AddForce(ReqForce);
}

