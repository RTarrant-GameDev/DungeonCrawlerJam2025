// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterComponent.h"
#include "DungeonCrawlerPlayer.h"

// Sets default values for this component's properties
UCharacterComponent::UCharacterComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UCharacterComponent::InitCharacterCreation(FString SelectedName, int32 SelectedRace, int32 Lockpick, int32 Arcana, int32 Attack,int32 Endurance, int32 Perception, int32 Wisdom)
{
	CharacterName = SelectedName;
	ChosenRace = static_cast<CharacterRace>(SelectedRace);

	LockpickSkill = Lockpick;
	ArcanaSkill = Arcana;
	AttackSkill = Attack;
	EnduranceSkill = Endurance;
	PerceptionSkill = Perception;
	WisdomSkill = Wisdom;

	Cast<ADungeonCrawlerPlayer>(GetOwner())->SetBonuses(EnduranceSkill, AttackSkill);
}

