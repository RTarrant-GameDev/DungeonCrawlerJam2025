// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonCrawlerActor.h"

// Sets default values
ADungeonCrawlerActor::ADungeonCrawlerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ActorCombatComponent = CreateDefaultSubobject<UCombatComponent>(TEXT("CombatComponent"));
	ActorHealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	ActorLineTraceComponent = CreateDefaultSubobject<ULineTraceComponent>(TEXT("LineTraceComponent"));
	ActorMovementComponent = CreateDefaultSubobject<UDungeonCrawlerMovementComponent>(TEXT("MovementComponent"));
}

// Called when the game starts or when spawned
void ADungeonCrawlerActor::BeginPlay()
{
	Super::BeginPlay();
	ActorHealthComponent->SetMaxHealth(HealthValue);
	ActorHealthComponent->SetCurrentHealth(HealthValue);

	ActorCombatComponent->SetArmorClass(ArmorClassValue);
}

// Called every frame
void ADungeonCrawlerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ActorHealthComponent->GetCurrentHealth() <= 0) {
		HandleDeath();
	}
	
	ActorLineTraceComponent->LineTraceFunct((GetActorLocation() + (GetActorForwardVector() * ActorMovementComponent->SnapDistance)), NeighbouringPawn);
}

void ADungeonCrawlerActor::HandleDeath()
{
	Destroy();
}
