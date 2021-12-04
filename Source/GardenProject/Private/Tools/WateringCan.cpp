#include "Tools/WateringCan.h"

AWateringCan::AWateringCan()
: AAbstractTool()
{}

void AWateringCan::UseToolOn(ACultivablePlot* PlotTarget)
{

  const ECultivablePlotStates CurrentPlotState = PlotTarget->GetState();

  // Check if the plot is not a normal plot and if there is some water in the
  // watering can.    
  if(this->NbOfUseRemaining != 0
  && CurrentPlotState != ECultivablePlotStates::Normal)
  {
    PlotTarget->Water();
    this->NbOfUseRemaining--;
  }

};

void AWateringCan::Refill()
{
  this->NbOfUseRemaining = AWateringCan::NB_OF_USE;
}
