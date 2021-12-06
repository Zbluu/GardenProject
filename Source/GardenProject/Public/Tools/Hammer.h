// Copyright Alexandre Depail. All Rights Reserved.

#pragma once

#include "Tools/AbstractTool.h"
#include "Math/Vector.h"
#include "Hammer.generated.h"

// Tool used by the player to build plots.
UCLASS()
class AHammer : public AAbstractTool
{
	GENERATED_BODY()

public:
	AHammer();

  // Used to save the location where the player wants to build a new plot.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FVector LastSelectedNewPlotLocation;

	// Function used to create a new plot actor. Defined in BP because we need to
	// create a new instance of CultivablePlotBP and not the C++ one which is
	// abstract. The class is more accessible via BP.
	UFUNCTION(BlueprintImplementableEvent)
	void SpawnNewPlotAt(const FVector& NewPlotLocation);

  virtual void UseToolOn(ACultivablePlot* PlotTarget) override;
};
