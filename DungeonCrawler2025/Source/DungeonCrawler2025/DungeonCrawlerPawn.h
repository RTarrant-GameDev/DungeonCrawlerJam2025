// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DungeonCrawlerActor.h"
#include "HealthComponent.h"
#include "CombatComponent.h"
#include "LineTraceComponent.h"
#include "DungeonCrawlerPawn.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONCRAWLER2025_API ADungeonCrawlerPawn : public ADungeonCrawlerActor
{
	GENERATED_BODY()
	
public:
	ADungeonCrawlerPawn();


#pragma region Components
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health")
	class UHealthComponent* PawnHealthComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat")
	class UCombatComponent* PawnCombatComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
	class ULineTraceComponent* PawnLineTraceComponent;

#pragma endregion Components

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
#pragma region Stats
	UPROPERTY(EditAnywhere)
	int32 HealthValue;

	UPROPERTY(EditAnywhere)
	int32 ArmorClassValue;
#pragma endregion Stats
};
