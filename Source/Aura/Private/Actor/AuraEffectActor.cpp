// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/AuraEffectActor.h"

#include "AbilitySystemComponent.h"
#include <AbilitySystemInterface.h>
#include <AbilitySystemBlueprintLibrary.h>
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Components/SphereComponent.h"



// Sets default values
AAuraEffectActor::AAuraEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));


	/* Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	SetRootComponent(Mesh);


	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");

	Sphere->SetupAttachment(GetRootComponent());*/
}

/*void AAuraEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OrherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)

	// TODO: Change This To Apply A Gameplay Effect. For Now, Using const_cast As A Hack!
{
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UAuraAttributeSet::StaticClass()));

		UAuraAttributeSet* MutableAuraAttributeSet = const_cast<UAuraAttributeSet*>(AuraAttributeSet);

		MutableAuraAttributeSet->SetHealth(AuraAttributeSet->GetHealth() + 25.f);

		MutableAuraAttributeSet->SetMana(AuraAttributeSet->GetMana() - 25.f);

		Destroy();
	}
}

void AAuraEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
} */

// Called when the game starts or when spawned
void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();

	/*Sphere->OnComponentBeginOverlap.AddDynamic(this, &AAuraEffectActor::OnOverlap);

	Sphere->OnComponentEndOverlap.AddDynamic(this, &AAuraEffectActor::EndOverlap);*/
}

void AAuraEffectActor::ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{	
	UAbilitySystemComponent* TargetAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target); // Option 2

	if (TargetAbilitySystemComponent == nullptr)
	{
		return;
	}

	check(GameplayEffectClass);

	FGameplayEffectContextHandle EffectContextHandle = TargetAbilitySystemComponent->MakeEffectContext();

	EffectContextHandle.AddSourceObject(this);

	FGameplayEffectSpecHandle EffectSpectHandle = TargetAbilitySystemComponent->MakeOutgoingSpec(GameplayEffectClass, 1.f, EffectContextHandle);

	TargetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*EffectSpectHandle.Data.Get());
	
	/*IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(Target); // Option 1 - Implementing The Interface To All The Actors

	if (ASCInterface) // Option 1 - Implementing The Interface To All The Actors
	{
		ASCInterface->GetAbilitySystemComponent(); // Option 1 - Implementing The Interface To All The Actors	
	}*/
}

// Called every frame
/*void AAuraEffectActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}*/

