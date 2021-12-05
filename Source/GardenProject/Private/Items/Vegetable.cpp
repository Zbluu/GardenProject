#include "Items/Vegetable.h"
#include "Core/GardenProjectGameMode.h"

AVegetable::AVegetable()
: AActor()
, Mesh(CreateDefaultSubobject<UStaticMeshComponent>("Mesh"))
{
  // Create a static mesh here. It'll be used in the Initialize function to set
  // the static mesh of the vegetable according to the game settings.

  // Set the static mesh to root component.
  this->SetRootComponent(this->Mesh);
}

void AVegetable::Initialize(
  const FString& _VegetableName
){
  this->VegetableName = _VegetableName;

  // Create the mesh.
  this->Mesh->SetStaticMesh(Cast<AGardenProjectGameMode>(
    this->GetWorld()->GetAuthGameMode())->GameSettings->
    VegetableSettings[this->VegetableName].Mesh);

  // Create a dynamic material instance to be able to change the mesh color.
  this->Material = this->Mesh->CreateDynamicMaterialInstance(0,
    this->Mesh->GetMaterial(0));

  // Assign the dynamic material to the mesh.
  this->Mesh->SetMaterial(0, this->Material);

  this->PlantingTime = 0;

  this->UpdateAppearance(this->GetState());
}

void AVegetable::UpdateAppearance(const EVegetableStates& NewState)
{
  // Get the vegetable settings.
  FVegetableGrowStateSettings& VegetableSettings = Cast<AGardenProjectGameMode>(
    this->GetWorld()->GetAuthGameMode())->GameSettings->
    VegetableSettings[this->VegetableName].States[NewState];

  // Get the color and scale of the mesh according to the vegetable state and
  // set the new values.
  this->Mesh->SetWorldScale3D(VegetableSettings.MeshScale);
  this->Material->SetVectorParameterValue(FName("Color"),
    VegetableSettings.MeshColor);
}

EVegetableStates AVegetable::GetState() const
{
  // Get the vegetable states settings.
  TMap<EVegetableStates, FVegetableGrowStateSettings>& VegetableSettings =
    Cast<AGardenProjectGameMode>(this->GetWorld()->GetAuthGameMode())->
    GameSettings->VegetableSettings[this->VegetableName].States;

  EVegetableStates Result;

  // Get the state of the vegetable according to the game settings (computed
  // thanks to the PlantingTime variable).
  if(this->PlantingTime <
    VegetableSettings[EVegetableStates::Young].SecondsBeforeEntryInThisState)
    Result = EVegetableStates::Sprout;
  else if(this->PlantingTime <
    VegetableSettings[EVegetableStates::Mature].SecondsBeforeEntryInThisState)
    Result = EVegetableStates::Young;
  else if(this->PlantingTime <
    VegetableSettings[EVegetableStates::Rotten].SecondsBeforeEntryInThisState)
    Result = EVegetableStates::Mature;
  else
    Result = EVegetableStates::Rotten;

  return Result;
}

void AVegetable::TickOnlyIfWet(float DeltaSeconds)
{
  // Get the old state to compare with the new later.
  const EVegetableStates OldState = this->GetState();

  // Add passed time (in seconds).
  this->PlantingTime += DeltaSeconds;

  // Get the new state.
  const EVegetableStates NewState = this->GetState();

  // Update the appearance is the state is not the same.
  if(OldState != NewState)
    this->UpdateAppearance(NewState);
}
