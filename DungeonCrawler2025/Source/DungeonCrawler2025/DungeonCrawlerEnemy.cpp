// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonCrawlerEnemy.h"
#include "DungeonCrawlerPlayer.h"
#include <Kismet/GameplayStatics.h>

ADungeonCrawlerEnemy::ADungeonCrawlerEnemy()
{
	EnemyInventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));
}

void ADungeonCrawlerEnemy::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ADungeonCrawlerEnemy::AttackFunction, 5.0f, true);
}

void ADungeonCrawlerEnemy::HandleDeath()
{
	Super::HandleDeath();

	ADungeonCrawlerPlayer* Player = Cast<ADungeonCrawlerPlayer>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	ADiceRollManager* DiceRoll = Player->PlayerSkillCheckComponent->DiceRoll;

	Player->ActorCombatComponent->SetTarget(nullptr);

	int32 WisdomBonus = Player->PlayerCharacterComponent->WisdomSkill;
	int32 PerceptionBonus = Player->PlayerCharacterComponent->PerceptionSkill;
	
	Player->PlayerLevelComponent->GiveXP(XPReward * 1 + (.25 * WisdomBonus));

	if ((DiceRoll->DiceRoll(20) + PerceptionBonus) >= PerceptionDifficulty) {
		Player->PlayerSkillCheckComponent->ScoreManager->AddScore(ScoreReward * 1 + (.25*PerceptionBonus));
	}

	if ((DiceRoll->DiceRoll(20) + PerceptionBonus) >= KeyPerceptionDifficulty){
		if (EnemyInventoryComponent->InventoryItems[0] != nullptr) {
			if (!(Player->PlayerInventoryComponent->InventoryItems.Contains(EnemyInventoryComponent->InventoryItems[0]))) {
				UE_LOG(LogTemp, Display, TEXT("Key Acquired!"))
					Player->PlayerInventoryComponent->AddToInventory(EnemyInventoryComponent->InventoryItems[0]);
				EnemyInventoryComponent->RemoveFromInventory(EnemyInventoryComponent->InventoryItems[0]);
			}
			else {
				Player->PlayerSkillCheckComponent->ScoreManager->AddScore(ScoreReward * 1 + (.75 * PerceptionBonus));
			}
		}
	}
}

void ADungeonCrawlerEnemy::DealDamage(int32 Damage)
{
	Super::DealDamage(Damage);
}

void ADungeonCrawlerEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (NeighbouringPawn != nullptr) {
		if (NeighbouringPawn->IsA(ADungeonCrawlerPlayer::StaticClass())) {
			ActorCombatComponent->SetTarget(NeighbouringPawn);
		}
	}
}

void ADungeonCrawlerEnemy::AttackFunction()
{
	if (this->ActorCombatComponent->Target != nullptr) {
		int32 HitDie = this->ActorCombatComponent->DiceRoll->DiceRoll(20);
		this->ActorCombatComponent->Attack(HitDie);
	}
}
