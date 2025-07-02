// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"
#include "ArmorItem.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONCRAWLER2025_API UArmorItem : public UInventoryItem
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "Armor Stats")
	int32 ArmorClassBonus;
};
