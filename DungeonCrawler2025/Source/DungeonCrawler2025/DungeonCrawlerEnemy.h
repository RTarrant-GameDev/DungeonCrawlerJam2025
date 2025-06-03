// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DungeonCrawlerActor.h"
#include "InventoryComponent.h"
#include "DungeonCrawlerEnemy.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONCRAWLER2025_API ADungeonCrawlerEnemy : public ADungeonCrawlerActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ADungeonCrawlerEnemy();

#pragma region Components

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Inventory")
	class UInventoryComponent* EnemyInventoryComponent;

#pragma endregion Components

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle TimerHandle;
	
	void AttackFunction();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyDetails")
	FString EnemyName;

	UPROPERTY(EditAnywhere, Category = "Rewards")
	int32 XPReward;

	UPROPERTY(EditAnywhere, Category = "Rewards")
	int32 ScoreReward;

	UPROPERTY(EditAnywhere, Category = "Rewards")
	int32 PerceptionDifficulty;

	UPROPERTY(EditAnywhere, Category = "Rewards")
	int32 KeyPerceptionDifficulty;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void HandleDeath() override;

	virtual void DealDamage(int32 Damage) override;
};
