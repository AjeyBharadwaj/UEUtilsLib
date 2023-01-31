// Fill out your copyright notice in the Description page of Project Settings.

#include "UEUtils.h"

static UEUtilsLogger utilsLogger;

AActor* UEUtils::SpawnActor(UWorld *world, UClass *uclass, FVector location, FRotator rotator, FActorSpawnParameters spawnInfo) {
	utilsLogger.LOG("Actor Spawnned");

	return world->SpawnActor<AActor>(uclass, location, rotator, spawnInfo);
}

AActor* UEUtils::SpawnActor(UWorld* world, UClass* uclass, FVector location, FRotator rotator) {
	FActorSpawnParameters spawnInfo;
	spawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	return SpawnActor(world, uclass, location, rotator, spawnInfo);
}

AActor* UEUtils::SpawnActor(UWorld* world, UClass* uclass) {
	return SpawnActor(world, uclass, FVector(0.0f), FRotator(0.0f));
}

AActor* UEUtils::SpawnActorDeffered(UWorld* world, UClass* uclass, FTransform spawnLocAndRotation) {
	utilsLogger.LOG("Actor Spawnned deffered");
	return world->SpawnActorDeferred<AActor>(uclass, spawnLocAndRotation);
}

void UEUtils::SpawnActorDefferedFinish(UWorld* world, AActor *actor, FTransform spawnLocAndRotation) {
	utilsLogger.LOG("Actor Spawnned deffered finshed");
	actor->FinishSpawning(spawnLocAndRotation);
}
