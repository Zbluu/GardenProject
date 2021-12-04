// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Core/GameSettings.h"
#include "GardenProjectGameMode.generated.h"

UCLASS(minimalapi)
class AGardenProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGardenProjectGameMode();

	UPROPERTY(BlueprintReadWrite)
	UGameSettings * GameSettings;

};
