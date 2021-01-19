// Fill out your copyright notice in the Description page of Project Settings.


#include "ACTCharacter.h"
#include "Abilities/ACTGameplayAbility.h"

// Sets default values
AACTCharacter::AACTCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystem = CreateDefaultSubobject<UACTAbilitySystemComponent>(TEXT("AbilitySystem"));
	AttributeSet = CreateDefaultSubobject<UACTAttributeSet>(TEXT("AttributeSet"));
}

UAbilitySystemComponent* AACTCharacter::GetAbilitySystemComponent() const 
{
	return AbilitySystem;
}

float AACTCharacter::GetHealth() const
{
	if (!AttributeSet)
	return 1.f;

	return AttributeSet->GetHealth();
}

float AACTCharacter::GetMaxHealth() const
{
	return AttributeSet->GetMaxHealth();
}

// Called when the game starts or when spawned
void AACTCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (AbilitySystem != nullptr)
	{
		if (HasAuthority() && GameplayAbilities.Num() > 0)
		{
			for (auto i = 0; i < GameplayAbilities.Num(); i++)
			{
				if (GameplayAbilities[i] == nullptr)
				{
					continue;
				}
				AbilitySystem->GiveAbility(FGameplayAbilitySpec(GameplayAbilities[i].GetDefaultObject(), 1, 0));
			}
		}

		AbilitySystem->InitAbilityActorInfo(this, this);
	}
}

// Called every frame
void AACTCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AACTCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
