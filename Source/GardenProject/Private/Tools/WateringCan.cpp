#include "Tools/WateringCan.h"

AWateringCan::AWateringCan()
: AAbstractTool()
{}

void AWateringCan::UseToolOn(ACultivablePlot* PlotTarget){

  const ECultivablePlotStates CurrentPlotState = PlotTarget->GetState();

  // Check if the plot is plowed or has a planted vegetable.
  if(CurrentPlotState != ECultivablePlotStates::Normal)
  {
    PlotTarget->Water();
    this->NbOfUseRemaining--;
  }

};

void AWateringCan::Refill(){
  this->NbOfUseRemaining = AWateringCan::NB_OF_USE;
}
