// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "TestingGrounds_05.h"
#include "TestingGrounds_05GameMode.h"
#include "TestingGrounds_05HUD.h"
#include "TestingGrounds_05Character.h"

ATestingGrounds_05GameMode::ATestingGrounds_05GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATestingGrounds_05HUD::StaticClass();
}
