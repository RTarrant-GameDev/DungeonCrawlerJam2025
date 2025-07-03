// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonCrawlerPlayer.h"
#include "DungeonCrawlerChicken.h"
#include "DungeonCrawlerEnemy.h"
#include "DungeonCrawlerSkillCheck.h"
#include <Kismet/GameplayStatics.h>
#include "Blueprint/UserWidget.h"
#include <UObject/UnrealTypePrivate.h>

ADungeonCrawlerPlayer::ADungeonCrawlerPlayer()
{
	PlayerSkillCheckComponent = CreateDefaultSubobject<USkillCheckComponent>(TEXT("SkillCheckComponent"));
	PlayerLevelComponent = CreateDefaultSubobject<ULevelComponent>(TEXT("LevelComponent"));
	PlayerCharacterComponent = CreateDefaultSubobject<UCharacterComponent>(TEXT("CharacterComponent"));
	PlayerInventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));
	PlayerCharacterEquipmentComponent = CreateDefaultSubobject<UCharacterEquipmentComponent>(TEXT("CharacterEquipmentComponent"));
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

	PlayerInputComponent->BindAction("PauseGame", IE_Pressed, this, &ADungeonCrawlerPlayer::PauseGame);
	PlayerInputComponent->BindAction("DisplayCharacterSheet", IE_Pressed, this, &ADungeonCrawlerPlayer::DisplayCharacterSheet);

	PlayerInputComponent->BindAction("EquipWeapon", IE_Pressed, this, &ADungeonCrawlerPlayer::EquipWeapon);
	PlayerInputComponent->BindAction("UnequipWeapon", IE_Pressed, this, &ADungeonCrawlerPlayer::UnequipWeapon);
}

void ADungeonCrawlerPlayer::BeginPlay()
{
	Super::BeginPlay();

	PlayerLevelComponent->Init();

	if (HitFlashWidgetClass) {

		HitFlashWidget = CreateWidget<UUserWidget>(GetWorld(), HitFlashWidgetClass);

		if (HitFlashWidget) {
			HitFlashWidget->AddToViewport(0);
		}

	}
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
			PlayerSkillCheckComponent->HasKey = false;
		}
		else if (NeighbouringPawn->IsA(ADungeonCrawlerSkillCheck::StaticClass())) {

			ADungeonCrawlerSkillCheck* SkillCheckPawn = Cast<ADungeonCrawlerSkillCheck>(NeighbouringPawn);

			ActorCombatComponent->SetTarget(nullptr);
			PlayerSkillCheckComponent->SetTarget(SkillCheckPawn);

			for(UInventoryItem* Item : PlayerInventoryComponent->InventoryItems) {
				if (Item == SkillCheckPawn->Key) {
					PlayerSkillCheckComponent->HasKey = true;
				}
			}
		}
	}
	else if (NeighbouringPawn == nullptr) {
		ActorCombatComponent->SetTarget(nullptr);
		PlayerSkillCheckComponent->SetTarget(nullptr);
		PlayerSkillCheckComponent->HasKey = false;
	}
}

void ADungeonCrawlerPlayer::DealDamage(int32 Damage)
{
	Super::DealDamage(Damage);

	if (HitSound) {
		UGameplayStatics::PlaySound2D(this, HitSound);
	}

	if (HitFlashWidget) {
		UWidgetAnimation* FlashAnim = nullptr;

		const FName AnimName = FName("HitFlashAnim");
		UClass* WidgetClass = HitFlashWidget->GetClass();

		// Search for animation by sifting through all class properties
		for (TFieldIterator<FObjectProperty> PropIt(WidgetClass); PropIt; ++PropIt) {
			FObjectProperty* Property = *PropIt;

			if (Property && Property->PropertyClass == UWidgetAnimation::StaticClass()) {
				if (Property->GetFName() == AnimName) {
					FlashAnim = Cast<UWidgetAnimation>(Property->GetObjectPropertyValue_InContainer(HitFlashWidget));
					break;
				}
			}
		}

		if (FlashAnim)
		{
			HitFlashWidget->PlayAnimation(FlashAnim);
		}
	}
}


void ADungeonCrawlerPlayer::SetBonuses(int32 Health, int32 Attack)
{
	ActorHealthComponent->SetMaxHealth(HealthValue + Health);
	ActorHealthComponent->SetCurrentHealth(HealthValue + Health);
	ActorCombatComponent->AttackBonus = Attack;
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

void ADungeonCrawlerPlayer::DisplayCharacterSheet()
{
	CharacterSheetWidget = CreateWidget<UUserWidget>(GetWorld(), CharacterSheetWidgetClass);

	if (CharacterSheetWidget) {
		CharacterSheetWidget->AddToViewport(4);
	}
}

void ADungeonCrawlerPlayer::EquipWeapon()
{
	PlayerCharacterEquipmentComponent->EquipWeapon(TestWeapon);
}

void ADungeonCrawlerPlayer::UnequipWeapon()
{
	PlayerCharacterEquipmentComponent->UnequipWeapon();
}
