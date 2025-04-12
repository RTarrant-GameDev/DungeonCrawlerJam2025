// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatComponent.h"
#include <Kismet/GameplayStatics.h>

UCombatComponent::UCombatComponent()
{
}

void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADiceRollManager::StaticClass(), FoundActors);

	DiceRoll = Cast<ADiceRollManager>(FoundActors[0]);
}

int32 UCombatComponent::DamageRoll()
{
	return DiceRoll->DiceRoll(6);
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
