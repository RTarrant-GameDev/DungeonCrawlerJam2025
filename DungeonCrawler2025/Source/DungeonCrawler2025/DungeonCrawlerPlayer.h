// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DungeonCrawlerActor.h"
#include "SkillCheckComponent.h"
#include "LevelComponent.h"
#include "CharacterComponent.h"
#include "Animation/WidgetAnimation.h"
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

#pragma endregion Components

#pragma region Hit Variables

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> HitFlashWidgetClass;

#pragma endregion Hit Variables

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void DealDamage(int32 Damage) override;

	void SetBonuses(int32 Health, int32 Attack);

	void PlayerRotateLeft();
	void PlayerRotateRight();
	void PlayerMoveForward();
	void PlayerMoveBackward();
	void PlayerMoveLeft();
	void PlayerMoveRight();

	UFUNCTION(BlueprintImplementableEvent, Category = "Pause")
	void PauseGame();

private:
	// Instance of the widget
	UUserWidget* HitFlashWidget;
};
