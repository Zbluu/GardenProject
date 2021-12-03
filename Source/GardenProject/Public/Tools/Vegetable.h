// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Containers/UnrealString.h"
#include "Tools/AbstractTool.h"
#include "Vegetable.generated.h"

// Enum to list all of the possible states of a vegetable.
UENUM()
enum EVegetableStates
{
	Sprout,				// Default state when planted.
  Young,				// Vegetable is too young to be eaten.
	Mature,				// Perfect moment to collect the vegetable.
  Rotten				// Player waited too long, the vegetable is rotten.
};

// Class used to create a new vegetable that can be planted, stored or sell.
UCLASS()
class AVegetable : public AAbstractTool
{
	GENERATED_BODY()

public:
	AVegetable();

	// Name of the vegetable type.
	FString VegetableName;

	// Used to save the current state of the plot.
	EVegetableStates VegetableState;

	// Remember the time (in seconds) when the player planted it
	// (-1 if not planted).
	int PlantingTime = -1;

	// Called when the vegetable needs to grow up (advancesto a new state).
	UFUNCTION(BlueprintCallable)
	void GrowUp();

	virtual void UseToolOn(ACultivablePlot* PlotTarget) override;
};
