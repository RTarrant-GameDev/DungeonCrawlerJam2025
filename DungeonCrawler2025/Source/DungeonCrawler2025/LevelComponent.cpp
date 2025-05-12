// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelComponent.h"
#include <Kismet/KismetMathLibrary.h>

// Sets default values for this component's properties
ULevelComponent::ULevelComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULevelComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void ULevelComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (CurrentXP >= MaxXP) {
		LevelUp();
	}
}

//Only call once on BeginPlay to set values
void ULevelComponent::Init()
{
	Level = 1;
	MaxXP = 50;
	CurrentXP = 0;
	bShowLevelUpButton = false;
}

float ULevelComponent::GetXPPercentage()
{
	return (
		UKismetMathLibrary::Multiply_IntFloat(CurrentXP, 1.0f) /
		UKismetMathLibrary::Multiply_IntFloat(MaxXP, 1.0f)
		);
}

void ULevelComponent::GiveXP(int32 XPToGive)
{
	CurrentXP += XPToGive;
}

void ULevelComponent::LevelUp()
{
	Level++;
	MaxXP = int32(float(MaxXP)* 1.05f);
	CurrentXP = 0;
	SkillPoints+=10;
	bShowLevelUpButton = true;
}

