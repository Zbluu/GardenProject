// Copyright Alexandre Depail. All Rights Reserved.

#pragma once

#include "Plots/CultivablePlot.h"
#include "CultivablePlotSaveStruct.generated.h"

// Used to convert a Vegetable actor into a savable struct.
USTRUCT(BlueprintType, Blueprintable)
struct FVegetableSaveStruct{
  GENERATED_BODY()

  UPROPERTY()
  FVector ActorLocation;

  UPROPERTY()
  FString VegetableName;

  UPROPERTY()
  float PlantingTime;
};


// Used to convert a CultivablePlot actor into a savable struct.
USTRUCT(BlueprintType, Blueprintable)
struct FCultivablePlotSaveStruct{
  GENERATED_BODY()

  UPROPERTY()
  FVector ActorLocation;

  UPROPERTY()
  int TimeOfLastWatering;

  UPROPERTY()
  ECultivablePlotStates CultivablePlotState;

  UPROPERTY()
  FVegetableSaveStruct Vegetable;
};
