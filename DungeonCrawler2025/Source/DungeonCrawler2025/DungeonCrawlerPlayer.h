// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DungeonCrawlerPawn.h"
#include "SkillCheckComponent.h"
#include "DungeonCrawlerPlayer.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONCRAWLER2025_API ADungeonCrawlerPlayer : public ADungeonCrawlerPawn
{
	GENERATED_BODY()
	
public:
	ADungeonCrawlerPlayer();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

#pragma region Components
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Skill Check")
	class USkillCheckComponent* PlayerSkillCheckComponent;
#pragma endregion Components

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
