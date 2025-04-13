// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DungeonCrawlerActor.h"
#include "LineTraceComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONCRAWLER2025_API ULineTraceComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULineTraceComponent();

	UFUNCTION(BlueprintCallable, Category = "Line Trace")
	bool LineTraceFunct(FVector TargetLocation, ADungeonCrawlerActor*& OutHitPawn);
		
};
