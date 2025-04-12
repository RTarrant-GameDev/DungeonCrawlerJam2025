// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DiceRollManager.generated.h"

UCLASS()
class DUNGEONCRAWLER2025_API ADiceRollManager : public AActor
{
	GENERATED_BODY()

public:	

	UFUNCTION(BlueprintCallable, Category = "Dice Roll")
	int32 DiceRoll(int32 DiceSides);
};
