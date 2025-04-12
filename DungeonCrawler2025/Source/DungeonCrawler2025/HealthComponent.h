// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONCRAWLER2025_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
#pragma region MaxHealth
	UPROPERTY(EditAnywhere, Category = "Health")
	int32 MaxHealth;

	UFUNCTION(BlueprintCallable, Category = "Health Settings")
	int32 GetMaxHealth();

	UFUNCTION(BlueprintCallable, Category = "Health Settings")
	void SetMaxHealth(int32 MaxHealthToSet);
#pragma endregion MaxHealth

#pragma region CurrentHealth
	int32 CurrentHealth;

	UFUNCTION(BlueprintCallable, Category = "Health Settings")
	int32 GetCurrentHealth();

	UFUNCTION(BlueprintCallable, Category = "Health Settings")
	void SetCurrentHealth(int32 CurrentHealthToSet);
#pragma endregion CurrentHealth

#pragma region HealthChangeFunctions
	UFUNCTION(BlueprintCallable, Category = "Health Settings")
	void AddHealth(int32 HealthToAdd);

	UFUNCTION(BlueprintCallable, Category = "Health Settings")
	void SubtractHealth(int32 HealthToSubtract);
#pragma endregion HealthChangeFunctions
	
	//Creating function for HUD to return Health percentage for health bar
	UFUNCTION(BlueprintCallable, Category = "Health Settings")
	float ReturnHealthPercentage();
};
