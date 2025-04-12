// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DungeonCrawlerActor.h"
#include "HealthComponent.h"
#include "DungeonCrawlerPlayer.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONCRAWLER2025_API ADungeonCrawlerPlayer : public ADungeonCrawlerActor
{
	GENERATED_BODY()
	
public:
	ADungeonCrawlerPlayer();

#pragma region Components
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health")
	class UHealthComponent* PlayerHealthComponent;
#pragma endregion Components

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
