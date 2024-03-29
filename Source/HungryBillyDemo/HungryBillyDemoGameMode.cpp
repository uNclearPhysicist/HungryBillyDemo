// Copyright Epic Games, Inc. All Rights Reserved.

#include "HungryBillyDemoGameMode.h"
#include "HungryBillyDemoCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHungryBillyDemoGameMode::AHungryBillyDemoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Assets/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
