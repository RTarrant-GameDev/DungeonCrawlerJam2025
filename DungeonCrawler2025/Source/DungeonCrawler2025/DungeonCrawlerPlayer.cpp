// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonCrawlerPlayer.h"

ADungeonCrawlerPlayer::ADungeonCrawlerPlayer()
{
	PlayerSkillCheckComponent = CreateDefaultSubobject<USkillCheckComponent>(TEXT("SkillCheckComponent"));
}

void ADungeonCrawlerPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	/*PlayerInputComponent->BindAction("RightRotate", IE_Pressed, this, &ADungeonCrawlerPlayer::RightRotate);
	PlayerInputComponent->BindAction("LeftRotate", IE_Pressed, this, &ADungeonCrawlerPlayer::LeftRotate);

	PlayerInputComponent->BindAction("MoveForward", IE_Pressed, this, &ADungeonCrawlerPlayer::MoveForward);
	PlayerInputComponent->BindAction("MoveBackward", IE_Pressed, this, &ADungeonCrawlerPlayer::MoveBackward);
	PlayerInputComponent->BindAction("MoveRight", IE_Pressed, this, &ADungeonCrawlerPlayer::MoveRight);
	PlayerInputComponent->BindAction("MoveLeft", IE_Pressed, this, &ADungeonCrawlerPlayer->PawnMovementComponent::MoveLeft);*/
}

void ADungeonCrawlerPlayer::BeginPlay()
{
	Super::BeginPlay();

}

void ADungeonCrawlerPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
