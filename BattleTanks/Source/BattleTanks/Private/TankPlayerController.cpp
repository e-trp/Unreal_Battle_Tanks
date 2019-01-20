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
		
		GetControllerTank()->AimAt(HitLocation);
	}


}

bool ATankPlayerController::GetSightRayHitLocation(FVector & OutHitLocation) const
{

	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrosshairXLocation, ViewportSizeY*CrosshairYLocation);
	FVector LookDirection;
	FVector  HitLocation;
	if (GetLookDirection(ScreenLocation, LookDirection))
	 {
		GetLookVectorHitLocation(LookDirection, HitLocation);
	 }
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	FVector CameraWorldLocation;
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection))
	{

		UE_LOG(LogTemp, Warning, TEXT("Look location: %s "), *LookDirection.ToString());
	}
	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection* LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}

	 HitLocation = FVector(0);
	 return false; 

}




ATank * ATankPlayerController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}


