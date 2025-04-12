// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonCrawlerEnemy.h"

ADungeonCrawlerEnemy::ADungeonCrawlerEnemy()
{
	EnemyHealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
}

void ADungeonCrawlerEnemy::BeginPlay()
{
	Super::BeginPlay();

	EnemyHealthComponent->SetMaxHealth(12);
	EnemyHealthComponent->SetMaxHealth(12);
}

void ADungeonCrawlerEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
