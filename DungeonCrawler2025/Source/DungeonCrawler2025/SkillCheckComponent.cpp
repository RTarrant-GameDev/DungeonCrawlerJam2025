// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillCheckComponent.h"
#include <Kismet/GameplayStatics.h>

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

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADiceRollManager::StaticClass(), FoundActors);

	DiceRoll = Cast<ADiceRollManager>(FoundActors[0]);
}


// Called every frame
void USkillCheckComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int32 USkillCheckComponent::SkillCheckRoll()
{
	return DiceRoll->DiceRoll(20);
}

void USkillCheckComponent::SetTarget(ADungeonCrawlerActor* TargetToSet)
{
	Target = TargetToSet;
}

