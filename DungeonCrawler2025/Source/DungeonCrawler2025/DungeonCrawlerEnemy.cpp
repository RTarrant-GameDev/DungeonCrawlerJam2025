// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonCrawlerEnemy.h"
#include "DungeonCrawlerPlayer.h"
#include <Kismet/GameplayStatics.h>

ADungeonCrawlerEnemy::ADungeonCrawlerEnemy()
{
}

void ADungeonCrawlerEnemy::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ADungeonCrawlerEnemy::AttackFunction, 5.0f, true);
}

void ADungeonCrawlerEnemy::HandleDeath()
{
	Super::HandleDeath();

	Cast<ADungeonCrawlerPlayer>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0))->PlayerLevelComponent->GiveXP(5);
}

void ADungeonCrawlerEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (NeighbouringPawn != nullptr) {
		if (NeighbouringPawn->IsA(ADungeonCrawlerPlayer::StaticClass())) {
			ActorCombatComponent->SetTarget(NeighbouringPawn);
		}
	}
}

void ADungeonCrawlerEnemy::AttackFunction()
{
	if (this->ActorCombatComponent->Target != nullptr) {
		this->ActorCombatComponent->Attack();
	}
}
