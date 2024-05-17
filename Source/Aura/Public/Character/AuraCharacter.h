// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:

	AAuraCharacter();  // Add Definition in AuraCharacter.cpp

	virtual void PossessedBy(AController* NewController) override; // Add Definition in AuraCharacter.cpp

	virtual void OnRep_PlayerState() override;	// Add Definition in AuraCharacter.cpp


	/** Combat Interface*/


	virtual int32 GetPlayerLevel() override; // Add Definition in AuraCharacter.cpp


	/** End Combat Interface*/


private:

	virtual void InitAbilityActorInfo() override; // Add Definition in AuraCharacter.cpp
};
