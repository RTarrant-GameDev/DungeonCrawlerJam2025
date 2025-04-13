// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonCrawlerMovementComponent.h"
#include "DungeonCrawlerActor.h"

// Sets default values for this component's properties
UDungeonCrawlerMovementComponent::UDungeonCrawlerMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDungeonCrawlerMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDungeonCrawlerMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDungeonCrawlerMovementComponent::RightRotate()
{
	FRotator NewRotation = GetOwner()->GetActorRotation();
	NewRotation.Yaw += 90.0f;
	GetOwner()->SetActorRotation(NewRotation);
}

void UDungeonCrawlerMovementComponent::LeftRotate()
{
	FRotator NewRotation = GetOwner()->GetActorRotation();
	NewRotation.Yaw -= 90.0f;
	GetOwner()->SetActorRotation(NewRotation);
}

void UDungeonCrawlerMovementComponent::MoveForward()
{
	FVector TargetLocation = GetOwner()->GetActorLocation() + (GetOwner()->GetActorForwardVector() * SnapDistance);

	ADungeonCrawlerActor* NeighbouringActor;

	if (!Cast<ADungeonCrawlerActor>(GetOwner())->ActorLineTraceComponent->LineTraceFunct(TargetLocation, NeighbouringActor)) {
		GetOwner()->SetActorLocation(TargetLocation);
	}
}

void UDungeonCrawlerMovementComponent::MoveBackward()
{
	FVector TargetLocation = GetOwner()->GetActorLocation() - (GetOwner()->GetActorForwardVector() * SnapDistance);

	ADungeonCrawlerActor* NeighbouringActor;

	if (!Cast<ADungeonCrawlerActor>(GetOwner())->ActorLineTraceComponent->LineTraceFunct(TargetLocation, NeighbouringActor)) {
		GetOwner()->SetActorLocation(TargetLocation);
	}
}

void UDungeonCrawlerMovementComponent::MoveRight()
{
	FVector TargetLocation = GetOwner()->GetActorLocation() + (GetOwner()->GetActorRightVector() * SnapDistance);

	ADungeonCrawlerActor* NeighbouringActor;

	if (!Cast<ADungeonCrawlerActor>(GetOwner())->ActorLineTraceComponent->LineTraceFunct(TargetLocation, NeighbouringActor)) {
		GetOwner()->SetActorLocation(TargetLocation);
	}
}

void UDungeonCrawlerMovementComponent::MoveLeft()
{
	FVector TargetLocation = GetOwner()->GetActorLocation() - (GetOwner()->GetActorRightVector() * SnapDistance);

	ADungeonCrawlerActor* NeighbouringActor;

	if (!Cast<ADungeonCrawlerActor>(GetOwner())->ActorLineTraceComponent->LineTraceFunct(TargetLocation, NeighbouringActor)) {
		GetOwner()->SetActorLocation(TargetLocation);
	}
}

