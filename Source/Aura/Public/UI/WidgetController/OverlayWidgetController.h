// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <GameplayEffectTypes.h>
#include "UI/WidgetController/AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"


class UAuraUserWidget;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealtChangedSignature, float, NewHealth);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealtChangedSignature, float, NewMaxHealth);


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChangedSignature, float, NewMana);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaChangedSignature, float, NewMaxMana);


USTRUCT(BlueprintType)
struct FUIWidgetRow : public FTableRowBase
{
	GENERATED_BODY()


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag MessageTag = FGameplayTag();


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Message = FText();


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UAuraUserWidget> MessageWidget;


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* Image = nullptr;
};

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class AURA_API UOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()


public:

	virtual void BroadcastInitialValues() override; // Add Definition in OverlayWidgetController.cpp

	virtual void BindCallbacksToDependencies() override; // Add Definition in OverlayWidgetController.cpp


	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnHealtChangedSignature OnHealthChanged;


	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxHealtChangedSignature OnMaxHealthChanged;


	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnManaChangedSignature OnManaChanged;


	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxManaChangedSignature OnMaxManaChanged;


protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widget Data")
	TObjectPtr<UDataTable> MessageWidgetDataTable;

	void HealthChanged(const FOnAttributeChangeData& Data) const; // Add Definition in OverlayWidgetController.cpp

	void MaxHealthChanged(const FOnAttributeChangeData& Data) const; // Add Definition in OverlayWidgetController.cpp


	void ManaChanged(const FOnAttributeChangeData& Data) const; // Add Definition in OverlayWidgetController.cpp

	void MaxManaChanged(const FOnAttributeChangeData& Data) const; // Add Definition in OverlayWidgetController.cpp
};
