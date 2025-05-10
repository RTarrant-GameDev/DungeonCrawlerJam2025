// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DiceRollManager.h"
#include "CombatComponent.generated.h"

// Forward declaration
class USoundBase;
class ADungeonCrawlerActor;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONCRAWLER2025_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Audio")
	USoundBase* AttackSound;

	UPROPERTY(EditDefaultsOnly, Category = "Audio")
	USoundBase* HitSound;

public:	

	UPROPERTY(EditAnywhere)
	int32 ArmorClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ADungeonCrawlerActor* Target;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DiceRoll")
	ADiceRollManager* DiceRoll;

	int32 AttackBonus;

	UFUNCTION(BlueprintCallable, Category = "Damage")
	int32 DamageRoll();

	UFUNCTION(BlueprintCallable, Category = "Attack")
	void Attack(int32 HitDie);

	void SetTarget(ADungeonCrawlerActor* TargetToSet);

	void SetArmorClass(int32 ArmorClassToSet);
};
