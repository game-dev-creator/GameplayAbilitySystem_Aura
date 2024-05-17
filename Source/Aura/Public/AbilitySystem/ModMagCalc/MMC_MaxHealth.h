// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "MMC_MaxHealth.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UMMC_MaxHealth : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()


public:

	UMMC_MaxHealth(); // Add Definition in MMC_MaxHealth.cpp

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override; // Add Definition in MMC_MaxHealth.cpp


private:

	FGameplayEffectAttributeCaptureDefinition VigorDef;
};
