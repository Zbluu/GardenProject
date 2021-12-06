// Copyright Alexandre Depail. All Rights Reserved.

#pragma once

#include "GameFramework/SaveGame.h"
#include "Items/Inventory.h"
#include "Save/CultivablePlotSaveStruct.h"
#include "Containers/Array.h"
#include "SaveData.generated.h"

UCLASS()
class USaveData : public USaveGame
{
GENERATED_BODY()

public:
  // -- Default properties --.
  UPROPERTY(VisibleAnywhere)
  FString SaveSlotName;

  UPROPERTY(VisibleAnywhere)
  uint32 UserIndex;

  // -- Custom properties --.
  UPROPERTY(VisibleAnywhere)
  FInventory Inventory;

  UPROPERTY(VisibleAnywhere)
  TArray<FCultivablePlotSaveStruct> Plots;

  USaveData();
};
