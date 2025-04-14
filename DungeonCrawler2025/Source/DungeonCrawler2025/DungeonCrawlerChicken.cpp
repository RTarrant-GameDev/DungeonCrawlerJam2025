// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonCrawlerChicken.h"
#include <Kismet/GameplayStatics.h>
#include "DungeonCrawlerPlayer.h"
#include "HealthComponent.h"

ADungeonCrawlerChicken::ADungeonCrawlerChicken()
{
}

void ADungeonCrawlerChicken::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADiceRollManager::StaticClass(), FoundActors);

	DiceRoll = Cast<ADiceRollManager>(FoundActors[0]);
}

void ADungeonCrawlerChicken::HandleDeath()
{
	Super::HandleDeath();

	Cast<ADungeonCrawlerPlayer>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0))->ActorHealthComponent->AddHealth(DiceRoll->DiceRoll(6));
}
