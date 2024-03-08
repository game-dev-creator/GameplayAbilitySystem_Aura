// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"


class UAttributeSet;
class UOverlayWidgetController;
class UAbilitySystemComponent;
class UAuraUserWidget;


struct FWidgetControllerParams;

/**
 * 
 */
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()


public:

	UPROPERTY()
	TObjectPtr<UAuraUserWidget> OverlayWidget; 

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams); // Add Definition in AuraHUD.cpp

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS); // Add Definition in AuraHUD.cpp

	/* protected:

	virtual void BeginPlay() override; // Add Definition in AuraHUD.cpp */


private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;


	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController; 


	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass; 
};
