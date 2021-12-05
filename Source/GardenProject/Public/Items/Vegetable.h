// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Containers/UnrealString.h"
#include "GameFramework/Actor.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/StaticMeshComponent.h"
#include "Vegetable.generated.h"

// Enum to list all of the possible states of a vegetable.
UENUM()
enum class EVegetableStates : uint8
{
	Sprout = 0,		// Default state when planted.
  Young,				// Vegetable is too young to be eaten.
	Mature,				// Perfect moment to collect the vegetable.
  Rotten				// Player waited too long, the vegetable is rotten.
};

// Class used to create a new vegetable that can be planted, stored or sell.
UCLASS()
class AVegetable : public AActor
{
	GENERATED_BODY()

public:
	AVegetable();

	// Called just after the vegetable is created, used to initialize the
 	// mesh and all the actor variables.
	void Initialize(
		const FString& _VegetableName
	);

	// Tick function called by the plot only when it's wet.
	void TickOnlyIfWet(float DeltaSeconds);

private:
	// Name of the vegetable type.
	FString VegetableName;

	// Remember the time (in seconds) when the player planted it
	// (-1 if not planted).
	float PlantingTime = -1;

	// Root component and static mesh (used in child class).
	UPROPERTY()
	UStaticMeshComponent* Mesh;

	UPROPERTY()
	UMaterialInstanceDynamic* Material;

	// Called to update the appearance of the mesh.
	void UpdateAppearance(const EVegetableStates& NewState);

	EVegetableStates GetState() const;
};
