// Copyright Epic Games, Inc. All Rights Reserved.

#include "andriodGameMode.h"
#include "andriodCharacter.h"

AandriodGameMode::AandriodGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = AandriodCharacter::StaticClass();	
}
