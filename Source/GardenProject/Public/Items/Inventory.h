#pragma once

#include "Containers/UnrealString.h"
#include "Containers/Map.h"
#include "Inventory.generated.h"

// Player inventory structure.
USTRUCT(BlueprintType, Blueprintable)
struct FInventory
{
  GENERATED_BODY()

  // Number of vegetables for each vegetable types.
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  TMap<FString, int> Vegetables;

  // Number of seeds for each vegetables.
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  TMap<FString, int> Seeds;

  // Amount of money.
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int Coins;
};
