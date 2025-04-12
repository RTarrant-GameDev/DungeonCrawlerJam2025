// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DungeonCrawlerActor.h"
#include "HealthComponent.h"
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
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health")
	class UHealthComponent* EnemyHealthComponent;
#pragma endregion Components

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
