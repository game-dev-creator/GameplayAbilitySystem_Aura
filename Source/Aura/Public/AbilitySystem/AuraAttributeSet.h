// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AuraAttributeSet.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties(){}

	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
	UAbilitySystemComponent* SourceAbilitySystemComponent = nullptr;


	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;


	UPROPERTY()
	AController* SourceController = nullptr;


	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;



	UPROPERTY()
	UAbilitySystemComponent* TargetAbilitySystemComponent = nullptr;


	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;


	UPROPERTY()
	AController* TargetController = nullptr;


	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;
};


/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()


public:

	UAuraAttributeSet(); // Add Definition in AuraAttributeSet.cpp

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; // Add Definition in AuraAttributeSet.cpp


	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override; // Add Definition in AuraAttributeSet.cpp


	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override; // Add Definition in AuraAttributeSet.cpp


	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData Health;


	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health);


	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital Attributes")
	FGameplayAttributeData MaxHealth;


	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth);


	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes")
	FGameplayAttributeData Mana;


	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana);


	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Vital Attributes")
	FGameplayAttributeData MaxMana;


	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana);


	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const; // Add Definition in AuraAttributeSet.cpp


	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const; // Add Definition in AuraAttributeSet.cpp	


	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const; // Add Definition in AuraAttributeSet.cpp


	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const; // Add Definition in AuraAttributeSet.cpp


private:

	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const; // Add Definition in AuraAttributeSet.cpp
};
