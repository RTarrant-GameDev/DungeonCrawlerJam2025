// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonCrawlerSkillCheck.h"
#include "DungeonCrawlerPlayer.h"
#include <Kismet/GameplayStatics.h>

void ADungeonCrawlerSkillCheck::BeginPlay()
{
	Super::BeginPlay();
}

void ADungeonCrawlerSkillCheck::HandleDeath()
{
	Super::HandleDeath();
	Cast<ADungeonCrawlerPlayer>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0))->PlayerLevelComponent->GiveXP(XPReward* Cast<ADungeonCrawlerPlayer>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0))->PlayerCharacterComponent->WisdomSkill);
}
