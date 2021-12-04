#include "Tools/Hammer.h"

AHammer::AHammer()
: AAbstractTool()
{}

void AHammer::SelectNewPlotLocation(const EPlotLocation& NewPlotLocation)
{
  this->LastSelectedNewPlotLocation = NewPlotLocation;
}

void AHammer::UseToolOn(ACultivablePlot* PlotTarget){
  // Spawn here a new actor.

};
