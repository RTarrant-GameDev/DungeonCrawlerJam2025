// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DungeonCrawlerActor.h"
#include "HealthComponent.h"
#include "DungeonCrawlerChicken.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONCRAWLER2025_API ADungeonCrawlerChicken : public ADungeonCrawlerActor
{
	GENERATED_BODY()
	
public:
	ADungeonCrawlerChicken();

#pragma region Components
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health")
	class UHealthComponent* ChickenHealthComponent;
#pragma endregion Components

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
