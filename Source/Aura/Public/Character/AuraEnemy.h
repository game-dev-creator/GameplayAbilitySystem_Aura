// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"



/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()


public:

	AAuraEnemy(); // Add Definition in AuraEnemy.cpp


	/** Enemy Interface */

	virtual void HighlightActor() override; // Add Definition in AuraEnemy.cpp

	virtual void UnHighlightActor() override; // Add Definition in AuraEnemy.cpp

	/** End Enemy Interface */


protected:

	virtual void BeginPlay() override; // Add Definition in AuraEnemy.cpp


	// UPROPERTY(BlueprintReadOnly)
	// bool bHighlighted = false;
	
};
