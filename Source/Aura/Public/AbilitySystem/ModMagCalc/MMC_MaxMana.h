// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "MMC_MaxMana.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UMMC_MaxMana : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()


public:

	UMMC_MaxMana(); // Add Definition in MMC_MaxMana.cpp

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override; // Add Definition in MMC_MaxMana.cpp


private:

	FGameplayEffectAttributeCaptureDefinition IntDef;	
};
