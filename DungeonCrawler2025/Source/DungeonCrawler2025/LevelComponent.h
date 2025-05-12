// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LevelComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONCRAWLER2025_API ULevelComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULevelComponent();

	UPROPERTY(BlueprintReadWrite, Category = "Level")
	int32 Level;

	UPROPERTY(BlueprintReadWrite, Category = "LevelUp")
	int32 SkillPoints;

	UPROPERTY(BlueprintReadWrite, Category = "LevelUp")
	bool bShowLevelUpButton;

	int32 CurrentXP;
	int32 MaxXP;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Init();

	UFUNCTION(BlueprintCallable, Category = "Level")
	float GetXPPercentage();

	void GiveXP(int32 XPToGive);

private:	
	void LevelUp();
};
