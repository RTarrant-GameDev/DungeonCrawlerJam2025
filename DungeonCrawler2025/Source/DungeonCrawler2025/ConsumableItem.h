// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"
#include "ConsumableItem.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONCRAWLER2025_API UConsumableItem : public UInventoryItem
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "Consumable Stats")
	int32 HealthToRestore;
};
