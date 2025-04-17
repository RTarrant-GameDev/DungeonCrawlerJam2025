// Fill out your copyright notice in the Description page of Project Settings.


#include "DiceRollManager.h"

int32 ADiceRollManager::DiceRoll(int32 DiceSides)
{
	return FMath::RandRange(1, DiceSides);
}

