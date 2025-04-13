// Fill out your copyright notice in the Description page of Project Settings.


#include "LineTraceComponent.h"
#include "DungeonCrawlerActor.h"


// Sets default values for this component's properties
ULineTraceComponent::ULineTraceComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

bool ULineTraceComponent::LineTraceFunct(FVector TargetLocation, ADungeonCrawlerActor*& OutHitPawn)
{
	FHitResult HitResult;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this->GetOwner());

	bool bHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		GetOwner()->GetActorLocation(),
		TargetLocation,
		ECC_Pawn,
		CollisionParams
	);

	if (bHit) {
		OutHitPawn = Cast<ADungeonCrawlerActor>(HitResult.GetActor()); // Assign the hit actor
		return true;
	}

	OutHitPawn = nullptr;
	return false;
}
