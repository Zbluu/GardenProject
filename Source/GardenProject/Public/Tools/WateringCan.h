// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Tools/AbstractTool.h"

// Tool used by the player to water plots.
UCLASS()
class AWateringCan : public AAbstractTool
{
	GENERATED_BODY()

public:
	AWateringCan();

  void UseToolOn(CultivablePlot* PlotTarget) override;

};
