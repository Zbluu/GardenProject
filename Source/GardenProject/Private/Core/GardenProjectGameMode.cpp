// Copyright Alexandre Depail. All Rights Reserved.

#include "Core/GardenProjectGameMode.h"
#include "Characters/GardenProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Save/SaveData.h"
#include "Plots/CultivablePlot.h"

AGardenProjectGameMode::AGardenProjectGameMode()
{
	// Set default pawn class to our Blueprinted character.
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(
		TEXT("/Game/Character/Blueprints/CharacterBP"));
	if (PlayerPawnBPClass.Class != NULL)
		DefaultPawnClass = PlayerPawnBPClass.Class;

	this->GameSettings = ConstructorHelpers::FObjectFinder<UGameSettings>(
		TEXT("/Game/Settings/GameSettings")).Object;
}

void AGardenProjectGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Get the character inventory reference.
	FInventory& Inventory = Cast<AGardenProjectCharacter>(UGameplayStatics::
		GetPlayerCharacter(GetWorld(),0))->Inventory;

	// Set coins to 100 by default.
	Inventory.Coins = 100;

	// Iterate in each vegetable types.
	for (const TPair<FString, FVegetableTypeSettings>& Pair
		: this->GameSettings->VegetableSettings)
	{
		 // Set amount of this vegetable type to 0.
		 Inventory.Vegetables.Add(Pair.Key, 0);

		 // Give one seed to the player by default.
		 Inventory.Seeds.Add(Pair.Key, 1);
	}
}

void AGardenProjectGameMode::SaveGame()
{
	// Create an empty data.
	USaveData* SaveData = Cast<USaveData>(UGameplayStatics::CreateSaveGameObject(
		USaveData::StaticClass()));

	// Fill the inventory data.
	SaveData->Inventory = Cast<AGardenProjectCharacter>(UGameplayStatics::
		GetPlayerCharacter(GetWorld(),0))->Inventory;

	// Get all plots.
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),
		ACultivablePlot::StaticClass(), Actors);
	for(AActor* Plot : Actors)
		SaveData->Plots.Add(ACultivablePlot::GetSaveStruct(
			Cast<ACultivablePlot>(Plot)));

	// Save Data.
	UGameplayStatics::SaveGameToSlot(SaveData, SaveData->SaveSlotName, SaveData->UserIndex);
}

void AGardenProjectGameMode::LoadGame()
{
	// If there is no save, abort.
	if(!this->PreviousGameExists())
		return;

	// First, we need to delete the current plots.
	TArray<AActor*> OldPlots;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),
		ACultivablePlot::StaticClass(), OldPlots);
	for(AActor* OldPlot : OldPlots)
		OldPlot->Destroy();

	// Load the data.
	USaveData* SaveData = Cast<USaveData>(UGameplayStatics::CreateSaveGameObject(
		USaveData::StaticClass()));
	SaveData = Cast<USaveData>(UGameplayStatics::LoadGameFromSlot(
		SaveData->SaveSlotName, SaveData->UserIndex));

	// Update existing game with data.
	// Load inventory.
	Cast<AGardenProjectCharacter>(UGameplayStatics::GetPlayerCharacter(
		GetWorld(),0))->Inventory = SaveData->Inventory;

	// Load plots.
	for(const FCultivablePlotSaveStruct& PlotSaveStruct : SaveData->Plots)
		ACultivablePlot::LoadPlot(PlotSaveStruct);
}


bool AGardenProjectGameMode::PreviousGameExists() const
{
	// Prefill the login data if saved.
	USaveData* SaveData = Cast<USaveData>(UGameplayStatics::CreateSaveGameObject(
		USaveData::StaticClass()));

	return UGameplayStatics::DoesSaveGameExist(SaveData->SaveSlotName,
		SaveData->UserIndex);
}
