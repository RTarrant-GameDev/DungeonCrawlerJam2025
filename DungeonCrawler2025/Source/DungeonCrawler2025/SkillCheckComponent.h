// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DungeonCrawlerActor.h"
#include "SkillCheckComponent.generated.h"


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
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ADungeonCrawlerActor* Target;

	/*UPROPERTY(EditAnywhere)
	ADiceRollManager* DiceRoll;*/

	UFUNCTION(BlueprintCallable, Category = "Skill Check")
	int32 SkillCheckRoll();

	void SetTarget(ADungeonCrawlerActor* TargetToSet);
};
