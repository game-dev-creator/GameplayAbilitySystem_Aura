// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"
#include <AbilitySystem/AuraAttributeSet.h>
#include <AbilitySystem/AuraAbilitySystemComponent.h>

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);


	OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());

	OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());


	OnManaChanged.Broadcast(AuraAttributeSet->GetMana());

	OnMaxManaChanged.Broadcast(AuraAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);


	// AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged); // Option 1

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data) 
			{
				OnHealthChanged.Broadcast(Data.NewValue);
			}
	); // Option 2


	// AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged); // Option 1


	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetMaxHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxHealthChanged.Broadcast(Data.NewValue);
			}
	); // Option 2

	
	// AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged); // Option 1


	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetManaAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnManaChanged.Broadcast(Data.NewValue);
			}
	); // Option 2


	// AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged); // Option 1


	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetMaxManaAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxManaChanged.Broadcast(Data.NewValue);
			}
	); // Option 2


	Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
	[this](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags) // Cut From AuraAbilitySystemComponent.cpp:
			{
				// For Example, Say That Tag = Message.HealthPotion

				// "A.1".MatchesTag ("A") Will Return True, "A".MatchesTag("A.1") Will Return False
				
				// "Message.HealthPotion".MatchesTag ("Message") Will Return True, "Message".MatchesTag("Message.HealthPotion") Will Return False

				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));

				if (Tag.MatchesTag(MessageTag))
				{
					const FUIWidgetRow* Row = GetDataTebaleRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);

					MessgaeWidgetRowDelegate.Broadcast(*Row);
				}

				//TODO: Broadcast the tag To The Widaget Controller

				/* const FString Msg = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());

				GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Blue, Msg); */
			}
		}
    );
}

/* void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const // Option 1
{
	OnHealthChanged.Broadcast(Data.NewValue);
} */

/* void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const // Option 1
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
} */


/* void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const // Option 1
{
	OnManaChanged.Broadcast(Data.NewValue);
} */

/* void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const // Option 1
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
} */

