// Copyright Alexandre Depail. All Rights Reserved.

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

	// Number of current uses remaining of the WateringCan before the player needs
	// to refill it.
	UPROPERTY(BlueprintReadOnly)
	int NbOfUseRemaining = 0;

	// Called when the player is next to a well. Refill the watering can to
	// 100% of its capacity.
	UFUNCTION(BlueprintCallable)
	void Refill();

	virtual void UseToolOn(ACultivablePlot* PlotTarget) override;


};
