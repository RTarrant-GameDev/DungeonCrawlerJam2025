// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"
#include "WeaponItem.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONCRAWLER2025_API UWeaponItem : public UInventoryItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Weapon Stats")
	int32 AttackDamageBonus;
};
