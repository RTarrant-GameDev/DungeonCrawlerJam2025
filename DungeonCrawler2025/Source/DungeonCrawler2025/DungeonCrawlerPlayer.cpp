// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonCrawlerPlayer.h"
#include "DungeonCrawlerChicken.h"
#include "DungeonCrawlerEnemy.h"
#include "DungeonCrawlerSkillCheck.h"

ADungeonCrawlerPlayer::ADungeonCrawlerPlayer()
{
	PlayerSkillCheckComponent = CreateDefaultSubobject<USkillCheckComponent>(TEXT("SkillCheckComponent"));
	PlayerLevelComponent = CreateDefaultSubobject<ULevelComponent>(TEXT("LevelComponent"));
}

void ADungeonCrawlerPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("RightRotate", IE_Pressed, this, &ADungeonCrawlerPlayer::PlayerRotateRight);
	PlayerInputComponent->BindAction("LeftRotate", IE_Pressed, this, &ADungeonCrawlerPlayer::PlayerRotateLeft);

	PlayerInputComponent->BindAction("MoveForward", IE_Pressed, this, &ADungeonCrawlerPlayer::PlayerMoveForward);
	PlayerInputComponent->BindAction("MoveBackward", IE_Pressed, this, &ADungeonCrawlerPlayer::PlayerMoveBackward);
	PlayerInputComponent->BindAction("MoveRight", IE_Pressed, this, &ADungeonCrawlerPlayer::PlayerMoveRight);
	PlayerInputComponent->BindAction("MoveLeft", IE_Pressed, this, &ADungeonCrawlerPlayer::PlayerMoveLeft);
}

void ADungeonCrawlerPlayer::BeginPlay()
{
	Super::BeginPlay();

	PlayerLevelComponent->Init();
}

void ADungeonCrawlerPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	 
	if (GetActorRotation().Pitch > 270.0f && GetActorRotation().Pitch < 361.0f) SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
	if (GetActorRotation().Pitch < 0.0f) SetActorRotation(FRotator(0.0f, 270.0f, 0.0f));

	if (NeighbouringPawn != nullptr) {
		if (NeighbouringPawn->IsA(ADungeonCrawlerEnemy::StaticClass()) || NeighbouringPawn->IsA(ADungeonCrawlerChicken::StaticClass())) {
			ActorCombatComponent->SetTarget(NeighbouringPawn);
			PlayerSkillCheckComponent->SetTarget(nullptr);
		}
		else if (NeighbouringPawn->IsA(ADungeonCrawlerSkillCheck::StaticClass())) {
			ActorCombatComponent->SetTarget(nullptr);
			PlayerSkillCheckComponent->SetTarget(NeighbouringPawn);
		}
	}
}

void ADungeonCrawlerPlayer::PlayerRotateLeft()
{
	ActorMovementComponent->LeftRotate();
}

void ADungeonCrawlerPlayer::PlayerRotateRight()
{
	ActorMovementComponent->RightRotate();
}

void ADungeonCrawlerPlayer::PlayerMoveForward()
{
	ActorMovementComponent->MoveForward();
}

void ADungeonCrawlerPlayer::PlayerMoveBackward()
{
	ActorMovementComponent->MoveBackward();
}

void ADungeonCrawlerPlayer::PlayerMoveLeft()
{
	ActorMovementComponent->MoveLeft();
}

void ADungeonCrawlerPlayer::PlayerMoveRight()
{
	ActorMovementComponent->MoveRight();
}
