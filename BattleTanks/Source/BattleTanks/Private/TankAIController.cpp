// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTanks.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();


	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController cant find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController find player tank %s"), *PlayerTank->GetName());
	}
	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));

}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		GatControllerTank()->AimAt(GetPlayerTank()->GetActorLocation());

	}
}





ATank * ATankAIController::GatControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn)
	{
		return nullptr;
	}
    
	
	return Cast<ATank>(PlayerPawn);
}

