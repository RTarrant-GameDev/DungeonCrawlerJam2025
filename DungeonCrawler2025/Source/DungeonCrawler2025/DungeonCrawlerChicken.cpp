// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonCrawlerChicken.h"

ADungeonCrawlerChicken::ADungeonCrawlerChicken()
{
	ChickenHealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
}

void ADungeonCrawlerChicken::BeginPlay()
{
	ChickenHealthComponent->SetMaxHealth(1);
	ChickenHealthComponent->SetMaxHealth(1);
}
