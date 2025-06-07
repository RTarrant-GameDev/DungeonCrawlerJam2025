// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInventoryComponent::AddToInventory(UInventoryItem* ItemToAdd)
{
	InventoryItems.Push(ItemToAdd);

	//Check if Item is a door key, set boolean to true, wait 5 seconds, then reset boolean to false, ready to be set to true next time
	if (ItemToAdd->b_IsADoorKey == true) {
		ObtainedKey = true;

		this->GetOwner()->GetWorldTimerManager().SetTimer(ResetTimerHandle, this, &UInventoryComponent::ResetObtainedKeyBool, 2.5f, false);
	}
}

void UInventoryComponent::RemoveFromInventory(UInventoryItem* ItemToRemove)
{
	InventoryItems.Remove(ItemToRemove);
}

void UInventoryComponent::ResetObtainedKeyBool()
{
	ObtainedKey = false;
}

