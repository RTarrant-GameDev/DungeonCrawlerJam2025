// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DungeonCrawlerPawn.h"
#include "DungeonCrawlerChicken.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONCRAWLER2025_API ADungeonCrawlerChicken : public ADungeonCrawlerPawn
{
	GENERATED_BODY()
	
public:
	ADungeonCrawlerChicken();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
