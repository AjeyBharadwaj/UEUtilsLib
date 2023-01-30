// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/World.h"
#include "CoreMinimal.h"

#include "UEUtilsBaseBall.h"

#include "UEUtilsLogger.h"

namespace UEUtils {
	//TODO : Can we add default parameters and everything same ?
	AActor* SpawnActor(UWorld* world, UClass* uclass, FVector location, FRotator rotator, FActorSpawnParameters spawnInfo);
	AActor* SpawnActor(UWorld* world, UClass* uclass, FVector location, FRotator rotator);
	AActor* SpawnActor(UWorld* world, UClass* uclass);
};