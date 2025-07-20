// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryItem.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONCRAWLER2025_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

public:	

	void AddToInventory(UInventoryItem* ItemToAdd);

	void RemoveFromInventory(UInventoryItem* ItemToRemove);

	UFUNCTION(BlueprintCallable, Category = "Inventory Functions")
	TArray<UInventoryItem*> GetInventoryItems();

	UFUNCTION(BlueprintCallable, Category = "Inventory Functions")
	UInventoryItem* GetItem(int32 SlotNumber);
	
	UPROPERTY(EditAnywhere, Category = "Inventory Items")
	TArray<UInventoryItem*> InventoryItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Key")
	bool ObtainedKey;

	void ResetObtainedKeyBool();

	FTimerHandle ResetTimerHandle;
};
