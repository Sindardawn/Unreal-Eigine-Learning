// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShootItGameMode.h"
#include "ShootItHUD.h"
#include "ShootItCharacter.h"
#include "UObject/ConstructorHelpers.h"

AShootItGameMode::AShootItGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AShootItHUD::StaticClass();
}
