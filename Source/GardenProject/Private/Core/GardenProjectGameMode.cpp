// Copyright Epic Games, Inc. All Rights Reserved.

#include "Core/GardenProjectGameMode.h"
#include "Characters/GardenProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGardenProjectGameMode::AGardenProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Mannequin/Blueprints/CharacterBP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
