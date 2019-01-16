// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "BattleTanks.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	

	auto ControllerTank = GetControllerTank();
	if (!ControllerTank)
	{ 
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing %s"),*ControllerTank->GetName());
	}
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("Player ticking"));

}

void ATankPlayerController::AimTowardsCrosshair()
{
	if(!GetControllerTank())
	{
		return;
	}

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit location: %s "), *HitLocation.ToString());
	}


}

bool ATankPlayerController::GetSightRayHitLocation(FVector & OutHitLocation) const
{

	OutHitLocation = FVector(1.0);
	return true;
}




ATank * ATankPlayerController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

