#include "Tools/Vegetable.h"

AVegetable::AVegetable(){}

void AVegetable::GrowUp(){
  // If not already at the last state and if the vegetable is planted, we
  // increment the state.
  if(this->VegetableState != EVegetableStates::Rotten
  && this->PlantingTime != -1)
    this->VegetableState = static_cast<EVegetableStates>(
      static_cast<int>(this->VegetableState) + 1);
}

void AVegetable::UseToolOn(ACultivablePlot* PlotTarget){

  const ECultivablePlotStates CurrentPlotState = PlotTarget->GetState();

  // Basic checks of the plot state.
  if(CurrentPlotState == ECultivablePlotStates::Plowed)
  {
    // warning : can't plant vegetable here before plow the plot.
  }else if(CurrentPlotState == ECultivablePlotStates::HasVegetable)
  {
    // warning : there already is a vegetable on this plot.
  }else
  {
    PlotTarget->PlantVegetable(this);
    this->PlantingTime = 0;
  }
};
