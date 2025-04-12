// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DungeonCrawlerActor.h"
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
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
