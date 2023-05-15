// Copyright Epic Games, Inc. All Rights Reserved.

#include "ManeuverGearGameMode.h"
#include "PlayerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AManeuverGearGameMode::AManeuverGearGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/MyContent/Player/BP_PlayerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
