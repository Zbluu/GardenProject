// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Plots/AbstractPlot.h"

// Enum to list all of the possible states of a plot.
UENUM()
enum ECultivablePlotStates
{
  Normal,				// Default state.
  Plowed,				// Player used a hoe on the plot.
  HasVegetable,	// Player planted a vegetable.
};

// Class used to create a new plot when the player build it with his hammer.
UCLASS()
class ACultivablePlot : public AAbstractPlot
{
	GENERATED_BODY()

public:
	ACultivablePlot();

	// Used to save the current state of the plot.
	ECultivablePlotStates CultivablePlotState;

	// Remember the last time (in seconds) that the plot was watered.
	int TimeOfLastWatering;

	// Vegetable of the plot (can be NULL).
	AVegetable* Vegetable;

	// Called when player use a hoe on this plot.
	void Plow();

	// Called when player wants to plant a new vegetable on this plot.
	void PlantVegetable(AVegetable* NewVegetable);

	// Called when player wants to collect the current vegetable of this plot.
	void CollectVegetable();

};
