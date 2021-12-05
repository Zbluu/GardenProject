#include "Plots/CultivablePlot.h"
#include "Core/GardenProjectGameMode.h"

ACultivablePlot::ACultivablePlot()
: AAbstractPlot()
{
  // Enable ticks.
  SetActorTickEnabled(true);
  PrimaryActorTick.bCanEverTick = true;
}

void ACultivablePlot::BeginPlay()
{
  Super::BeginPlay();

  // If the plot was created with default value.
  if(this->TimeOfLastWatering == -1)
  {
    // Get the game settings via the game mode.
    AGardenProjectGameMode* GameMode = Cast<AGardenProjectGameMode>(
      GetWorld()->GetAuthGameMode());

    // We need to set it above the limit defined in game settings.
    this->TimeOfLastWatering = GameMode->GameSettings->CultivablePlotSettings.
      SecondsBeforeBecomingDry + 1;
  }
}

void ACultivablePlot::Tick(float DeltaSeconds)
{
  Super::Tick(DeltaSeconds);
  // UE_LOG(LogTemp, Warning, TEXT("Some warning message") );

  // Get the dry/wet state before adding time.
  const bool bIsDryBefore = this->IsDry();

  // No need to update the appearance if the plot is dry.
  if(!bIsDryBefore)
  {
    // Add passed time (in seconds).
    this->TimeOfLastWatering += DeltaSeconds;

    // Check if the plot is dry after added the time.
    if(this->IsDry())
      this->UpdateAppearance();

    // If still wet, we can update the vegetable because it only grows up if
    // the plot is dry.
    else if(this->GetState() == ECultivablePlotStates::HasVegetable
    && IsValid(this->Vegetable))
      Vegetable->TickOnlyIfWet(DeltaSeconds);
  }
}

void ACultivablePlot::Water()
{

  // Reset the timer of the last watering.
  this->TimeOfLastWatering = 0;

  // Update the appearance of the plot.
  this->UpdateAppearance();
}

void ACultivablePlot::Plow()
{
  // Player can't plow a plot if it's not in normal state.
  if(this->CultivablePlotState != ECultivablePlotStates::Normal)
    return;

  // Set the new plot state.
  this->CultivablePlotState = ECultivablePlotStates::Plowed;

  // Update the appearance of the plot.
  this->UpdateAppearance();
}

void ACultivablePlot::PlantVegetable(const FString& VegetableName)
{
  // Get the game settings via the game mode.
  AGardenProjectGameMode* GameMode = Cast<AGardenProjectGameMode>(
    GetWorld()->GetAuthGameMode());

  // Compute the vegetable location and add offset to put it above the plot.
  const FVector VegetableLocation = this->GetActorLocation() +
    FVector(0, 0, 30);

  // Create and assign the new vegetable actor to this plot vegetable.
  this->Vegetable = this->GetWorld()->SpawnActor<AVegetable>(
    VegetableLocation, FRotator());
  this->Vegetable->Initialize(VegetableName);

  // Set the new plot state.
  this->CultivablePlotState = ECultivablePlotStates::HasVegetable;

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

  return this->TimeOfLastWatering > Cast<AGardenProjectGameMode>(
      GetWorld()->GetAuthGameMode())->GameSettings->CultivablePlotSettings
      .SecondsBeforeBecomingDry;
}
