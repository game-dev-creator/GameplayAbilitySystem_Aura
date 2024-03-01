// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuraUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraUserWidget : public UUserWidget
{
	GENERATED_BODY()
	

public:


	UFUNCTION(BlueprintReadOnly)
	void SetWidgetController(UObject* InWidgetController); // Add Definition in AuraUserWidget.cpp


	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController; 


protected:

	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet(); // Add Definition in AuraUserWidget.cpp
};
