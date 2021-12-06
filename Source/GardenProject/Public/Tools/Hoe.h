// Copyright Alexandre Depail. All Rights Reserved.

#pragma once

#include "Tools/AbstractTool.h"
#include "Hoe.generated.h"

// Tool used by the player to plow plots.
UCLASS()
class AHoe : public AAbstractTool
{
	GENERATED_BODY()

public:
	AHoe();

	virtual void UseToolOn(ACultivablePlot* PlotTarget) override;

};
