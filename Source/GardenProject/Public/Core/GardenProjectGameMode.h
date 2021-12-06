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

	// Settings of the entire game defined in BP.
	UPROPERTY(BlueprintReadWrite)
	UGameSettings * GameSettings;

	AGardenProjectGameMode();

	virtual void BeginPlay() override;

	// Store a save of the current game in local file.
	UFUNCTION(BlueprintCallable)
	void SaveGame();

	// Load the last local save of a previous game.
	UFUNCTION(BlueprintCallable)
	void LoadGame();

	// Check if a save exists.
	UFUNCTION(BlueprintCallable)
	bool PreviousGameExists() const;

};
