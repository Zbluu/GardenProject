// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Plots/AbstractPlot.h"
#include "CultivablePlot.generated.h"

// We need to forward declare this class to prevent circular dependencies.
class AVegetable;

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

	// Vegetable of the plot (can be NULL).
  UPROPERTY()
	AVegetable* Vegetable;

  // Called when the player use a watering-can (not empty) on the plot.
  UFUNCTION(BlueprintCallable)
  void Water();

	// Called when player use a hoe on this plot.
  UFUNCTION(BlueprintCallable)
	void Plow();

	// Called when player wants to plant a new vegetable on this plot.
  UFUNCTION(BlueprintCallable)
  void PlantVegetable(AVegetable* NewVegetable);

	// Called when player wants to collect the current vegetable of this plot.
  UFUNCTION(BlueprintCallable)
	void CollectVegetable();

  UFUNCTION(BlueprintCallable)
  ECultivablePlotStates GetState() const;

  UFUNCTION(BlueprintCallable)
  bool IsDry() const;

protected:
  // Used to save the current state of the plot.
  ECultivablePlotStates CultivablePlotState = ECultivablePlotStates::Normal;

  // Remember the last time (in seconds) that the plot was watered.
  // TODO : default value equal to the limit defined in settings
  int TimeOfLastWatering = 21;

  // Function overrided in BP to update the appearance of the plot when the
  UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
  void UpdateAppearance();

};
