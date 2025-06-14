// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DungeonCrawlerActor.h"
#include "InventoryItem.h"
#include "DungeonCrawlerSkillCheck.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONCRAWLER2025_API ADungeonCrawlerSkillCheck : public ADungeonCrawlerActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADungeonCrawlerSkillCheck();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	virtual void HandleDeath() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkillCheck")
	int32 SkillCheckDifficulty;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkillCheck")
	FString SkillCheckType;

	UPROPERTY(EditAnywhere, Category = "SkillCheck")
	int32 ScoreReward;
	UPROPERTY(EditAnywhere, Category = "SkillCheck")
	int32 XPReward;

	UPROPERTY(EditAnywhere, Category = "SkillCheck")
	UInventoryItem* Key;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CheckStatus")
	bool Failed;
};
