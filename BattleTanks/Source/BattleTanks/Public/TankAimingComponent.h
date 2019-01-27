// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector HitLocation);

	UTankAimingComponent();

	void SetBarrelReferences(UStaticMeshComponent *BarrelToSet);

private:
	UStaticMeshComponent *Barrel = nullptr;

};