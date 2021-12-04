// Copyright Epic Games, Inc. All Rights Reserved.

#include "Core/GardenProjectGameMode.h"
#include "Characters/GardenProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

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
