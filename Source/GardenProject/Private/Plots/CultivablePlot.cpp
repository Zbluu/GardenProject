#include "Plots/CultivablePlot.h"

ACultivablePlot::ACultivablePlot()
: AAbstractPlot()
{}

void ACultivablePlot::Water()
{

  // Reset the timer of the last watering.
  this->TimeOfLastWatering = 0;

  // Update the appearance of the plot.
  this->UpdateAppearance();
}

void ACultivablePlot::Plow()
{

  // Set the new plot state.
  this->CultivablePlotState = ECultivablePlotStates::Plowed;

  // Update the appearance of the plot.
  this->UpdateAppearance();
}

void ACultivablePlot::PlantVegetable(AVegetable* NewVegetable)
{

  // Set the new plot state.
  this->CultivablePlotState = ECultivablePlotStates::HasVegetable;

  // Assign the new vegetable to this plot vegetable now planted.
  this->Vegetable = NewVegetable;

  // Update the appearance of the plot.
  this->UpdateAppearance();
}

void ACultivablePlot::CollectVegetable()
{

  // Set the new plot state.
  this->CultivablePlotState = ECultivablePlotStates::Normal;

  // Delete the vegetable from this plot.
  this->Vegetable = NULL;

  // Update the appearance of the plot.
  this->UpdateAppearance();
}

ECultivablePlotStates ACultivablePlot::GetState() const
{
  return this->CultivablePlotState;
}

bool ACultivablePlot::IsDry() const
{
  // TOOO : change this
  return TimeOfLastWatering > 20;
}
