#include "Tools/Hammer.h"

AHammer::AHammer()
: AAbstractTool()
{}

void AHammer::UseToolOn(ACultivablePlot* PlotTarget){
  // Spawn here a new actor.
  this->SpawnNewPlotAt(this->LastSelectedNewPlotLocation);
};
