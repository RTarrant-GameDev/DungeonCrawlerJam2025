// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DungeonCrawlerActor.h"
#include "CombatComponent.generated.h"


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

public:	

	UPROPERTY(EditAnywhere)
	int32 ArmorClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ADungeonCrawlerActor* Target;

	/*UPROPERTY(EditAnywhere)
	ADiceRollManager* DiceRoll;*/

	UFUNCTION(BlueprintCallable, Category = "Damage")
	int32 DamageRoll();

	UFUNCTION(BlueprintCallable, Category = "Attack")
	void Attack();

	void SetTarget(ADungeonCrawlerActor* TargetToSet);

	void SetArmorClass(int32 ArmorClassToSet);
};
