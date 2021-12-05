#include "Tools/WateringCan.h"
#include "Kismet/GameplayStatics.h"
#include "Core/GardenProjectGameMode.h"

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
  // Get the game settings via the game mode.
  AGardenProjectGameMode* GameMode = Cast<AGardenProjectGameMode>(
   GetWorld()->GetAuthGameMode());

  this->NbOfUseRemaining = GameMode->GameSettings->WateringCanMaxUses;
}
