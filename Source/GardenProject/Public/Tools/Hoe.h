// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Tools/AbstractTool.h"

// Tool used by the player to plow plots.
UCLASS()
class AHoe : public AAbstractTool
{
	GENERATED_BODY()

public:
	AHoe();

	void UseToolOn(CultivablePlot* PlotTarget) override;

};
