// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonCrawlerPawn.h"

ADungeonCrawlerPawn::ADungeonCrawlerPawn()
{
	PawnHealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	PawnCombatComponent = CreateDefaultSubobject<UCombatComponent>(TEXT("CombatComponent"));
	PawnLineTraceComponent = CreateDefaultSubobject<ULineTraceComponent>(TEXT("LineTraceComponent"));
}

void ADungeonCrawlerPawn::BeginPlay()
{
	PawnHealthComponent->SetMaxHealth(HealthValue);
	PawnHealthComponent->SetCurrentHealth(HealthValue);

	PawnCombatComponent->SetArmorClass(ArmorClassValue);
}
