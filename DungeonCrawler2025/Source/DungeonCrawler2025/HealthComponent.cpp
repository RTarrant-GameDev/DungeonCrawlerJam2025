// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include <Kismet/KismetMathLibrary.h>

int32 UHealthComponent::GetMaxHealth()
{
	return MaxHealth;
}

void UHealthComponent::SetMaxHealth(int32 MaxHealthToSet)
{
	MaxHealth = MaxHealthToSet;
}

int32 UHealthComponent::GetCurrentHealth()
{
	return CurrentHealth;
}

void UHealthComponent::SetCurrentHealth(int32 CurrentHealthToSet)
{
	CurrentHealth = CurrentHealthToSet;
}

void UHealthComponent::AddHealth(int32 HealthToAdd)
{
	CurrentHealth += HealthToAdd;
}

void UHealthComponent::SubtractHealth(int32 HealthToSubtract)
{
	CurrentHealth -= HealthToSubtract;
}

float UHealthComponent::ReturnHealthPercentage()
{
	return (
			UKismetMathLibrary::Multiply_IntFloat(CurrentHealth, 1.0f) / 
			UKismetMathLibrary::Multiply_IntFloat(MaxHealth, 1.0f) 
		   );
}
