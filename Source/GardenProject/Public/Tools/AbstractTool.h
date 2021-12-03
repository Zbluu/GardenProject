// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "Plots/CultivablePlot.h"
#include "AbstractTool.generated.h"

// Usable objects used by the player in game. This is an ABSTRACT class so you
// should not try to intanciate it. Class used to create child class for each
// different tool.
UCLASS(Abstract)
class AAbstractTool : public AActor
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
  virtual void UseToolOn(ACultivablePlot* PlotTarget);

protected:
	AAbstractTool();

};
