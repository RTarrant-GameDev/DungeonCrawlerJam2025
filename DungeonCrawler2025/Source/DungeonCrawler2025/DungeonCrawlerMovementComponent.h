// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DungeonCrawlerMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONCRAWLER2025_API UDungeonCrawlerMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDungeonCrawlerMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void RightRotate();
	void LeftRotate();

	void MoveForward();
	void MoveBackward();
	void MoveRight();
	void MoveLeft();

	UPROPERTY(EditAnywhere)
	float SnapDistance;

	UPROPERTY(EditAnywhere)
	float RotationSpeed;
};
