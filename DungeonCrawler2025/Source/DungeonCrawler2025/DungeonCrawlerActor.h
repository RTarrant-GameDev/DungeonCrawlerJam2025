// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthComponent.h"
#include "CombatComponent.h"
#include "LineTraceComponent.h"
#include "DungeonCrawlerMovementComponent.h"
#include "DungeonCrawlerActor.generated.h"

// Forward declaration
class USoundBase;

UCLASS()
class DUNGEONCRAWLER2025_API ADungeonCrawlerActor : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADungeonCrawlerActor();

#pragma region Components

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat")
	class UCombatComponent* ActorCombatComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health")
	class UHealthComponent* ActorHealthComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
	class ULineTraceComponent* ActorLineTraceComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
	class UDungeonCrawlerMovementComponent* ActorMovementComponent;

#pragma endregion Components
	UPROPERTY(VisibleAnywhere, Category = "Pawn")
	ADungeonCrawlerActor* NeighbouringPawn;

#pragma region Stats
	UPROPERTY(EditAnywhere)
	int32 HealthValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ArmorClassValue;
#pragma endregion Stats

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Audio")
	USoundBase* HitSound;

	UPROPERTY(EditDefaultsOnly, Category = "Audio")
	USoundBase* DeathSound;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void HandleDeath();

	virtual void DealDamage(int32 Damage);
};
