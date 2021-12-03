// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Tools/AbstractTool.h"
#include "Hammer.generated.h"

// Tool used by the player to build plots.
UCLASS()
class AHammer : public AAbstractTool
{
	GENERATED_BODY()

public:
	AHammer();

  // Used to save the location where the player wants to build a new plot.
  EPlotLocation LastSelectedNewPlotLocation;

  // Called each time the player look at a possible location to build a new plot.
	UFUNCTION(BlueprintCallable)
  void SelectNewPlotLocation(const EPlotLocation& NewPlotLocation);

  virtual void UseToolOn(ACultivablePlot* PlotTarget) override;
};
