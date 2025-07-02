// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterEquipmentComponent.h"
#include "DungeonCrawlerPlayer.h"

// Sets default values for this component's properties
UCharacterEquipmentComponent::UCharacterEquipmentComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called every frame
void UCharacterEquipmentComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UCharacterEquipmentComponent::EquipArmor(UArmorItem* NewArmor)
{
	if (EquippedArmor != NULL) {
		UnequipArmor();
	}
	
	EquippedArmor = NewArmor;

	ArmorClass = EquippedArmor->ArmorClassBonus;
	Cast<ADungeonCrawlerPlayer>(GetOwner())->ArmorClassValue += ArmorClass;
}

void UCharacterEquipmentComponent::UnequipArmor()
{
	EquippedArmor = NULL;
	Cast<ADungeonCrawlerPlayer>(GetOwner())->ArmorClassValue -= ArmorClass;
	ArmorClass = 0;
}

