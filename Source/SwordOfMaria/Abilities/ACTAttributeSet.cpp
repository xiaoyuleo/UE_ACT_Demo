// Fill out your copyright notice in the Description page of Project Settings.


#include "ACTAttributeSet.h"
#include "ACTAbilitySystemComponent.h"
#include "../ACTCharacter.h"


UACTAttributeSet::UACTAttributeSet()
	: Health(1.f)
	, MaxHealth(1.f)
{
}

void UACTAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const 
{
  Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UACTAttributeSet, Health);
	DOREPLIFETIME(UACTAttributeSet, MaxHealth);
}

void UACTAttributeSet::OnRep_Health(const FGameplayAttributeData& OldValue) 
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UACTAttributeSet, Health, OldValue); 
}

void UACTAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldValue) 
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UACTAttributeSet, MaxHealth, OldValue);  
}
