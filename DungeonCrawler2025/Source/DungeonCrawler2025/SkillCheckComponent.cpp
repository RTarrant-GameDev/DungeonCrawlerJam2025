// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillCheckComponent.h"

// Sets default values for this component's properties
USkillCheckComponent::USkillCheckComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USkillCheckComponent::BeginPlay()
{
	Super::BeginPlay();

	//Add code for getting DiceRoll Manager here
	
}


// Called every frame
void USkillCheckComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int32 USkillCheckComponent::SkillCheckRoll()
{
	//add dice roll code here
	int32 Placeholder = 6;
	return Placeholder;
}

void USkillCheckComponent::SetTarget(ADungeonCrawlerActor* TargetToSet)
{
	Target = TargetToSet;
}

