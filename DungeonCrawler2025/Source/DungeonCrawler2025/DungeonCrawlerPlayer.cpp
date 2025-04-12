// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonCrawlerPlayer.h"

ADungeonCrawlerPlayer::ADungeonCrawlerPlayer()
{
	PlayerHealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	PlayerCombatComponent = CreateDefaultSubobject<UCombatComponent>(TEXT("CombatComponent"));
	PlayerSkillCheckComponent = CreateDefaultSubobject<USkillCheckComponent>(TEXT("SkillCheckComponent"));
}

void ADungeonCrawlerPlayer::BeginPlay()
{
	Super::BeginPlay();

	PlayerHealthComponent->SetMaxHealth(12);
	PlayerHealthComponent->SetCurrentHealth(12);

	PlayerCombatComponent->SetArmorClass(14);
}

void ADungeonCrawlerPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
