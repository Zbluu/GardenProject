// Copyright Alexandre Depail. All Rights Reserved.

#pragma once

#include "Containers/UnrealString.h"
#include "GameFramework/Actor.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/StaticMeshComponent.h"
#include "Save/CultivablePlotSaveStruct.h"
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
	// Name of the vegetable type.
	UPROPERTY(BlueprintReadOnly)
	FString VegetableName;

	AVegetable();

	// Called just after the vegetable is created, used to initialize the
 	// mesh and all the actor variables.
	void Initialize(
		const FString& _VegetableName
	);

	// Tick function called by the plot only when it's wet.
	void TickOnlyIfWet(float DeltaSeconds);

	// Return the state of the vegetable.
	UFUNCTION(BlueprintCallable)
	EVegetableStates GetState() const;

	// Get a savable struct.
  static FVegetableSaveStruct GetSaveStruct(AVegetable* Vegetable);
  // Create a vegetable actor from a savable struct.
  static AVegetable* LoadVegetable(const FVegetableSaveStruct& SaveStruct);

private:

	// Remember the time (in seconds) when the player planted it
	// (-1 if not planted).
	float PlantingTime = -1;

	// Root component and static mesh (used in child class).
	UPROPERTY()
	UStaticMeshComponent* Mesh;

	// Dynamic material instance of the mesh used to change the mesh color.
	UPROPERTY()
	UMaterialInstanceDynamic* Material;

	// Called to update the appearance of the mesh.
	void UpdateAppearance(const EVegetableStates& NewState);
};
