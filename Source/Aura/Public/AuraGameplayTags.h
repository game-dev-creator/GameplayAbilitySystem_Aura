// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <GameplayTagContainer.h>

/**
 * AuraGameplayTags
 * 
 * Singleton Containing Native Gameplay Tags
 */

struct FAuraGameplayTags
{

public:

	static const FAuraGameplayTags& Get()
	{
		return GameplayTags;
	}

	static void InitializeNativeGameplayTags(); // Add Definition in AuraGameplayTags.cpp


	FGameplayTag Attributes_Secondary_Armor;


protected:


private:

	static FAuraGameplayTags GameplayTags;
};
