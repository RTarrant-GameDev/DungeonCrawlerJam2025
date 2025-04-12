// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatComponent.h"

UCombatComponent::UCombatComponent()
{
}

void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();

	//Add code for getting DiceRoll Manager here
}

int32 UCombatComponent::DamageRoll()
{
	//add damage roll code here
	int32 Damage = 6;
	return Damage;
}

void UCombatComponent::Attack()
{
	//add dice roll code here
}

void UCombatComponent::SetTarget(ADungeonCrawlerActor* TargetToSet)
{
	Target = TargetToSet;
}

void UCombatComponent::SetArmorClass(int32 ArmorClassToSet)
{
	ArmorClass = ArmorClassToSet;
}
