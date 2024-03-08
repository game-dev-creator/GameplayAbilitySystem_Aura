// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"


class UInputMappingContext;

class UInputAction;

struct FInputActionValue;

class IEnemyInterface;


/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AAuraPlayerController(); // Add Definition in AuraPlayerController.cpp 

	virtual void PlayerTick(float DeltaTime) override; // Add Definition in AuraPlayerController.cpp 


protected:

	virtual void BeginPlay() override; // Add Definition in AuraPlayerController.cpp

	virtual void SetupInputComponent() override; // Add Definition in AuraPlayerController.cpp 

private:

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> AuraContext; 


	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;


	void Move(const FInputActionValue& InputActionValue); // Add Definition in AuraPlayerController.cpp 

	void CursorTrace(); // Add Definition in AuraPlayerController.cpp


	TObjectPtr<IEnemyInterface> LastActor;

	TObjectPtr <IEnemyInterface> ThisActor;
};
