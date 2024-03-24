// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AuraAttributeSet.h"
#include "GameFramework/Character.h"
#include "GameplayEffectExtension.h"
#include <Net/UnrealNetwork.h>
#include <AbilitySystemBlueprintLibrary.h>


UAuraAttributeSet::UAuraAttributeSet()
{
	InitHealth(50.f);

	InitMaxHealth(100.f);

	InitMana(10.f);

	InitMaxMana(50.f);
}


void UAuraAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Health, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);


	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Mana, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void UAuraAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeBaseChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());

		// UE_LOG(LogTemp, Warning, TEXT("Health: %f"), NewValue);
	}


	/*if (Attribute == GetMaxHealthAttribute())
	{
		UE_LOG(LogTemp, Warning, TEXT("MaxHealth: %f"), NewValue);
	}*/


	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMana());

		// UE_LOG(LogTemp, Warning, TEXT("Mana: %f"), NewValue);
	}


	/*if (Attribute == GetMaxManaAttribute())
	{
		UE_LOG(LogTemp, Warning, TEXT("MaxMana: %f"), NewValue);
	}*/
}

void UAuraAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const
{
	// Source = Causer Of The Effect, Target = Target Of The Effect (Owner Of This AttributeSet)

	// const FGameplayEffectContextHandle EffectContextHandle = Data.EffectSpec.GetContext(); // Option 1

	Props.EffectContextHandle = Data.EffectSpec.GetContext(); // Option 2

	// const UAbilitySystemComponent* SourceAbilitySystemComponent = EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent(); // Option 1

	Props.SourceAbilitySystemComponent = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent(); // Option 2

	if (IsValid(Props.SourceAbilitySystemComponent) && Props.SourceAbilitySystemComponent->AbilityActorInfo.IsValid() && Props.SourceAbilitySystemComponent->AbilityActorInfo->AvatarActor.IsValid())
	{
		// AActor* SourceAvatarActor = Props.SourceAbilitySystemComponent->AbilityActorInfo->AvatarActor.Get(); // Option 1

		Props.SourceAvatarActor = Props.SourceAbilitySystemComponent->AbilityActorInfo->AvatarActor.Get(); // Option 2

		// const AController* SourceController = Props.SourceAbilitySystemComponent->AbilityActorInfo->PlayerController.Get(); // Option 1

		Props.SourceController = Props.SourceAbilitySystemComponent->AbilityActorInfo->PlayerController.Get(); // Option 2

		if (Props.SourceController == nullptr && Props.SourceAvatarActor != nullptr)
		{
			if (const APawn* Pawn = Cast<APawn>(Props.SourceAvatarActor))
			{
				Props.SourceController = Pawn->GetController();
			}
		}

		if (Props.SourceController)
		{
			Props.SourceCharacter = Cast<ACharacter>(Props.SourceController->GetPawn());
		}
	}

	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		// AActor* TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get(); // Option 1

		Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get(); // Option 2

		// AController* TargetController = Data.Target.AbilityActorInfo->PlayerController.Get(); // Option 1

		Props.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get(); // Option 2

		// ACharacter* TargetCharacter = Cast<ACharacter>(TargetAvatarActor); // Option 1

		Props.TargetCharacter = Cast<ACharacter>(Props.TargetAvatarActor); // Option 2

		// UAbilitySystemComponent* TargetAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetAvatarActor); // Option 1

		Props.TargetAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Props.TargetAvatarActor); // Option 2

	}
}

void UAuraAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	/* if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		UE_LOG(LogTemp, Warning, TEXT("Health From GetHealth(): %f"), GetHealth());

		UE_LOG(LogTemp, Warning, TEXT("Magnitude: %f"), Data.EvaluatedData.Magnitude);
	}*/

	FEffectProperties Props;

	SetEffectProperties(Data, Props);
}


void UAuraAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Health, OldHealth);
}


void UAuraAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MaxHealth, OldMaxHealth);
}


void UAuraAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Mana, OldMana);
}


void UAuraAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MaxMana, OldMaxMana);
}


