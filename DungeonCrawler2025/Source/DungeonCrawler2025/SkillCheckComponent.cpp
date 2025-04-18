// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillCheckComponent.h"
#include <Kismet/GameplayStatics.h>
#include "DungeonCrawlerPlayer.h"

// Sets default values for this component's properties
USkillCheckComponent::USkillCheckComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USkillCheckComponent::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADiceRollManager::StaticClass(), FoundActors);

	DiceRoll = Cast<ADiceRollManager>(FoundActors[0]);

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AScoreManager::StaticClass(), FoundActors);

	ScoreManager = Cast<AScoreManager>(FoundActors[0]);
}

void USkillCheckComponent::SkillCheck(int32 SkillDie)
{	
	if (Target->SkillCheckType == "Lockpick") {
		SkillDie += Cast<ADungeonCrawlerPlayer>(GetOwner())->PlayerCharacterComponent->LockpickSkill;
	}
	else if (Target->SkillCheckType == "Arcana") {
		SkillDie += Cast<ADungeonCrawlerPlayer>(GetOwner())->PlayerCharacterComponent->ArcanaSkill;
	}

	if (SkillDie >= (Target->SkillCheckDifficulty)) {
		ScoreManager->AddScore(Target->ScoreReward * (Cast<ADungeonCrawlerPlayer>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0))->PlayerCharacterComponent->PerceptionSkill));
		Target->HandleDeath();
	}
}

void USkillCheckComponent::SetTarget(ADungeonCrawlerActor* TargetToSet)
{
	Target = Cast<ADungeonCrawlerSkillCheck>(TargetToSet);
}

