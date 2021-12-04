// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Tools/AbstractTool.h"
#include "WateringCan.generated.h"

// Tool used by the player to water plots.
UCLASS()
class AWateringCan : public AAbstractTool
{
	GENERATED_BODY()

public:
	AWateringCan();

	// Decide how many times we can use the WateringCan before the player needs
	// to refill it.
	// TODO : change it to settings.
	UPROPERTY(BlueprintReadOnly)
	int NB_OF_USE = 4;

	UPROPERTY(BlueprintReadOnly)
	int NbOfUseRemaining = 0;

	UFUNCTION(BlueprintCallable)
	void Refill();

	virtual void UseToolOn(ACultivablePlot* PlotTarget) override;


};
