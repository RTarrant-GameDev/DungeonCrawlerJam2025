// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Animation/WidgetAnimation.h"
#include "CharacterComponent.h"
#include "CharacterEquipmentComponent.h"
#include "CoreMinimal.h"
#include "DungeonCrawlerActor.h"
#include "InventoryComponent.h"
#include "LevelComponent.h"
#include "SkillCheckComponent.h"
#include "DungeonCrawlerPlayer.generated.h"
 
// Forward declarations
class UUserWidget;
class UWidgetAnimation;

UCLASS()
class DUNGEONCRAWLER2025_API ADungeonCrawlerPlayer : public ADungeonCrawlerActor
{
	GENERATED_BODY()
	
public:
	ADungeonCrawlerPlayer();

#pragma region Components
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Skill Check")
	class USkillCheckComponent* PlayerSkillCheckComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Level")
	class ULevelComponent* PlayerLevelComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character")
	class UCharacterComponent* PlayerCharacterComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Inventory")
	class UInventoryComponent* PlayerInventoryComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character Equipment")
	class UCharacterEquipmentComponent* PlayerCharacterEquipmentComponent;

#pragma endregion Components

#pragma region Widget Variables

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> HitFlashWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> CharacterSheetWidgetClass;

#pragma endregion Widget Variables

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void DealDamage(int32 Damage) override;

	UPROPERTY(EditAnywhere, Category = "Armor Test")
	UArmorItem* TestArmor;

	void SetBonuses(int32 Health, int32 Attack);

	void PlayerRotateLeft();
	void PlayerRotateRight();
	void PlayerMoveForward();
	void PlayerMoveBackward();
	void PlayerMoveLeft();
	void PlayerMoveRight();

	UFUNCTION(BlueprintImplementableEvent, Category = "Pause")
	void PauseGame();

	void DisplayCharacterSheet();

private:
	// Instance of the widget
	UUserWidget* HitFlashWidget;

	// Instance of the widget
	UUserWidget* CharacterSheetWidget;
};
