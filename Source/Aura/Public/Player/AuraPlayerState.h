// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "AuraPlayerState.generated.h"


class UAbilitySystemComponent;

class UAttributeSet;

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	AAuraPlayerState(); // Add Definition in AuraPlayerState.cpp


	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override; // Add Definition in AuraPlayerState.cpp


	UAttributeSet* GetAttributeSet() const { return AttributeSet; }


protected:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;


	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	
};
