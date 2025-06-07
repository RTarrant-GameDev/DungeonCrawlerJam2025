// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InventoryItem.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class DUNGEONCRAWLER2025_API UInventoryItem : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "Item Info")
	FString ItemName;

	UPROPERTY(EditAnywhere, Category = "Item Info")
	FText ItemDesc;

	UPROPERTY(EditAnywhere, Category = "Door Key")
	bool b_IsADoorKey;
};
