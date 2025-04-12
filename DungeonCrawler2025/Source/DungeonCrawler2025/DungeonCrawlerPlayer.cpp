// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonCrawlerPlayer.h"

ADungeonCrawlerPlayer::ADungeonCrawlerPlayer()
{
	PlayerSkillCheckComponent = CreateDefaultSubobject<USkillCheckComponent>(TEXT("SkillCheckComponent"));
}

void ADungeonCrawlerPlayer::BeginPlay()
{
	Super::BeginPlay();

}

void ADungeonCrawlerPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
