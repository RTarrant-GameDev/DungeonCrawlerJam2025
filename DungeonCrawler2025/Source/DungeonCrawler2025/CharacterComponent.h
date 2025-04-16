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

	FString CharacterName;
	CharacterRace ChosenRace;

#pragma region Skills
	int32 LockpickSkill; //for skill checks
	int32 ArcanaSkill; // for skill checks
	int32 AttackSkill; // increase attack damage
	int32 EnduranceSkill; // increase health
	int32 PerceptionSkill; // score multiplier 
	int32 WisdomSkill; // increase XP gain
#pragma endregion Skills

public:	

	UFUNCTION(BlueprintCallable, Category = "CharacterCreation")
	void InitCharacterCreation(FString SelectedName, int32 SelectedRace, int32 Lockpick, int32 Arcana, int32 Attack, int32 Endurance, int32 Perception, int32 Wisdom);
};
