#pragma once

#include "Engine/DataAsset.h"
#include "Engine/Texture2D.h"
#include "Engine/StaticMesh.h"
#include "Items/Vegetable.h"
#include "Containers/UnrealString.h"
#include "Containers/Map.h"
#include "GameSettings.generated.h"

USTRUCT(BlueprintType, Blueprintable)
struct FCultivablePlotSettings{
  GENERATED_BODY()

  // Delay (in seconds) before the plot became dry after a watering.
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int SecondsBeforeBecomingDry;
};

// Used to define each state of a vegetable life cycle.
USTRUCT(BlueprintType, Blueprintable)
struct FVegetableGrowStateSettings{
  GENERATED_BODY()

  // At which time (in seconds) the vegetable can entry in this state.
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int SecondsBeforeEntryInThisState;

  // Color of the mesh.
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FColor MeshColor;

  // Scale of the mesh.
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FVector MeshScale;
};

// Define a type of vegetable.
USTRUCT(BlueprintType, Blueprintable)
struct FVegetableTypeSettings{
  GENERATED_BODY()

  // 2D icon of the vegetable.
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  UTexture2D* Icon;

  // 3D mesh of the vegetable.
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  UStaticMesh* Mesh;

  // Define each state of a vegetable life cycle.
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  TMap<EVegetableStates, FVegetableGrowStateSettings> States;

};

// Game settings overrided in BP and created in the GameMode.
UCLASS(BlueprintType)
class UGameSettings : public UDataAsset {
  GENERATED_BODY()

public:

  // Settings about CultivablePlots.
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FCultivablePlotSettings CultivablePlotSettings;

  // Settings about CultivablePlots.
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  TMap<FString, FVegetableTypeSettings> VegetableSettings;

  // Nb of uses of the watering. After, the player needs to refill it.
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int WateringCanMaxUses;

};
