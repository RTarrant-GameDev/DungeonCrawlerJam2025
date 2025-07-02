// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ArmorItem.h"
#include "CharacterEquipmentComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONCRAWLER2025_API UCharacterEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCharacterEquipmentComponent();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, Category = "Character Equipment")
	UArmorItem* EquippedArmor;

	UPROPERTY(VisibleAnywhere, Category="Character Equipment Stats")
	int32 ArmorClass;

	UPROPERTY(VisibleAnywhere, Category = "Character Equipment Stats")
	int32 WeaponAttack;

	UFUNCTION(BlueprintCallable)
	void EquipArmor(UArmorItem* NewArmor);

	UFUNCTION(BlueprintCallable)
	void UnequipArmor();
};
