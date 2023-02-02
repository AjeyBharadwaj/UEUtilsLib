// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "UEUtilsLogger.h"

#include "UEUtilsBaseActor.generated.h"

UCLASS()
class UEUTILSLIB_API AUEUtilsBaseActor : public AActor
{
	GENERATED_BODY()
	
protected:
	UEUtilsLogger* logger;
	UStaticMeshComponent* staticMesh;

public:	
	// Sets default values for this actor's properties
	AUEUtilsBaseActor();
	AUEUtilsBaseActor(const TCHAR* path);

	void init(const void* path);
	void EnableGravity(bool enable = true);
	void EnablePhysics(bool enable = true);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
