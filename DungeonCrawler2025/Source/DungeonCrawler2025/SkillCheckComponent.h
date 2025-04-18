// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DiceRollManager.h"
#include "DungeonCrawlerSkillCheck.h"
#include "ScoreManager.h"
#include "SkillCheckComponent.generated.h"


class ADungeonCrawlerActor;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONCRAWLER2025_API USkillCheckComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USkillCheckComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ADungeonCrawlerSkillCheck* Target;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DiceRoll")
	ADiceRollManager* DiceRoll;

	UPROPERTY(EditAnywhere)
	AScoreManager* ScoreManager;

	UFUNCTION(BlueprintCallable, Category = "Skill Check")
	void SkillCheck(int32 SkillDie);

	void SetTarget(ADungeonCrawlerActor* TargetToSet);
};
