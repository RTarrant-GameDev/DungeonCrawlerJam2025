// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterComponent.generated.h"

UENUM(BlueprintType)
enum class CharacterRace : uint8
{
	Human = 0 UMETA(DisplayName = "Human"),
	Elf = 1 UMETA(DisplayName = "Elf"),
	Dwarf = 2 UMETA(DisplayName = "Dwarf"),
	Orc = 3 UMETA(DisplayName = "Orc")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONCRAWLER2025_API UCharacterComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCharacterComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Details")
	FString CharacterName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Details")
	CharacterRace ChosenRace;

#pragma region Skills
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 LockpickSkill; //for skill checks
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 ArcanaSkill; // for skill checks
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 AttackSkill; // increase attack damage
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 EnduranceSkill; // increase health
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 PerceptionSkill; // score multiplier 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 WisdomSkill; // increase XP gain
#pragma endregion Skills

public:	

	UFUNCTION(BlueprintCallable, Category = "CharacterCreation")
	void InitCharacterCreation(FString SelectedName, int32 SelectedRace, int32 Lockpick, int32 Arcana, int32 Attack, int32 Endurance, int32 Perception, int32 Wisdom);

	UFUNCTION(BlueprintCallable, Category = "LevelUp")
	void LevelUpCharacterValues(int32 Lockpick, int32 Arcana, int32 Attack, int32 Endurance, int32 Perception, int32 Wisdom);
};
