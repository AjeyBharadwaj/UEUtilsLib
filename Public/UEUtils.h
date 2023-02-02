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

	AActor* SpawnActorDeffered(UWorld* world, UClass* uclass, FTransform spawnLocAndRotation);
	void SpawnActorDefferedFinish(UWorld* world, AActor* actor, FTransform spawnLocAndRotation);

	float RandomFloat(float min=0.0f, float max=1.0f);

};
