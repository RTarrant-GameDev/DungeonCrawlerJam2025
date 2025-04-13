// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonCrawlerPlayer.h"
#include "DungeonCrawlerChicken.h"
#include "DungeonCrawlerEnemy.h"
#include "DungeonCrawlerSkillCheck.h"

ADungeonCrawlerPlayer::ADungeonCrawlerPlayer()
{
	PlayerSkillCheckComponent = CreateDefaultSubobject<USkillCheckComponent>(TEXT("SkillCheckComponent"));

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

}

void ADungeonCrawlerPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	 
	if (GetActorRotation().Pitch > 270.0f && GetActorRotation().Pitch < 361.0f) SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
	if (GetActorRotation().Pitch < 0.0f) SetActorRotation(FRotator(0.0f, 270.0f, 0.0f));

	ADungeonCrawlerActor* NeighbouringPawn;

	if (PawnLineTraceComponent->LineTraceFunct((GetActorLocation() + (GetActorForwardVector() * PawnMovementComponent->SnapDistance)), NeighbouringPawn) && NeighbouringPawn != nullptr) {
		if (NeighbouringPawn->IsA(ADungeonCrawlerEnemy::StaticClass()) || NeighbouringPawn->IsA(ADungeonCrawlerChicken::StaticClass())) {
			PawnCombatComponent->SetTarget(NeighbouringPawn);
		}
		else if (NeighbouringPawn->IsA(ADungeonCrawlerSkillCheck::StaticClass())) {
			PlayerSkillCheckComponent->SetTarget(NeighbouringPawn);
		}
	}
}

void ADungeonCrawlerPlayer::PlayerRotateLeft()
{
	PawnMovementComponent->LeftRotate();
}

void ADungeonCrawlerPlayer::PlayerRotateRight()
{
	PawnMovementComponent->RightRotate();
}

void ADungeonCrawlerPlayer::PlayerMoveForward()
{
	PawnMovementComponent->MoveForward();
}

void ADungeonCrawlerPlayer::PlayerMoveBackward()
{
	PawnMovementComponent->MoveBackward();
}

void ADungeonCrawlerPlayer::PlayerMoveLeft()
{
	PawnMovementComponent->MoveLeft();
}

void ADungeonCrawlerPlayer::PlayerMoveRight()
{
	PawnMovementComponent->MoveRight();
}
