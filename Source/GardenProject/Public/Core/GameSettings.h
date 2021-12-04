#pragma once

#include "Engine/DataAsset.h"
#include "GameSettings.generated.h"

USTRUCT(BlueprintType, Blueprintable)
struct FCultivablePlotSettings{
  GENERATED_BODY()

  // Delay (in seconds) before the plot became dry after a watering.
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int SecondsBeforeBecomingDry;
};

UCLASS(BlueprintType)
class UGameSettings : public UDataAsset {
  GENERATED_BODY()

public:

  // Settings about CultivablePlots.
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FCultivablePlotSettings CultivablePlotSettings;

  // Nb of uses of the watering. After, the player needs to refill it.
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int WateringCanMaxUses;

};
