// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonCrawlerSkillCheck.h"
#include "DungeonCrawlerPlayer.h"
#include <Kismet/GameplayStatics.h>

ADungeonCrawlerSkillCheck::ADungeonCrawlerSkillCheck()
{
}

void ADungeonCrawlerSkillCheck::BeginPlay()
{
	Super::BeginPlay();
}

void ADungeonCrawlerSkillCheck::HandleDeath()
{
	Super::HandleDeath();

	ADungeonCrawlerPlayer* Player = Cast<ADungeonCrawlerPlayer>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	int32 PlayerWisdom = Player->PlayerCharacterComponent->WisdomSkill;
	Player->PlayerSkillCheckComponent->SetTarget(nullptr);
	Player->PlayerLevelComponent->GiveXP(XPReward * 1 + (.25*PlayerWisdom));
}
