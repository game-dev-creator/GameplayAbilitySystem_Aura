// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"


class UAbilitySystemComponent;

class UAttributeSet;


UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAuraCharacterBase();


	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override; // Add Definition in AuraCharacterBase.h


	UAttributeSet* GetAttributeSet() const { return AttributeSet; }


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;


	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;


	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

/* public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; */

};
