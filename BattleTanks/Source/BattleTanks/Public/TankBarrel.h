// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories=("Collision"))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	
	void Elevate(float DegreesPerSecond);

private:

	UPROPERTY(EditAnywhere, Category=Setup)
	float MaxDegreesPerSecond = 20;
	
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 30;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0;

	
};
