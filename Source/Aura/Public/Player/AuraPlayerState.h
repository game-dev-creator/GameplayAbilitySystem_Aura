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


	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; // Add Definition in AuraPlayerState.cpp


	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override; // Add Definition in AuraPlayerState.cpp


	UAttributeSet* GetAttributeSet() const { return AttributeSet; }


	FORCEINLINE int32 GetPlayerLevel() const { return Level; }


protected:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;


	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;


private:

	UPROPERTY(VisibleAnywhere, ReplicatedUsing = OnRep_Level)
	int32 Level = 1;


	UFUNCTION()
	void OnRep_Level(int32 OldLevel); // Add Definition in AuraPlayerState.cpp
};
