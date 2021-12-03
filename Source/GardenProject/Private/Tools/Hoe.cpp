#include "Tools/Hoe.h"

AHoe::AHoe(){}

void AHoe::UseToolOn(ACultivablePlot* PlotTarget){

  const ECultivablePlotStates CurrentPlotState = PlotTarget->GetState();

  // Check if the plot is not already plowed or has planted vegetable.
  if(CurrentPlotState != ECultivablePlotStates::Plowed
  && CurrentPlotState != ECultivablePlotStates::HasVegetable)
    PlotTarget->Plow();

};
