// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "UEUtilsLogger.h"

#include "UEUtilsBaseBall.generated.h"

UCLASS()
class UEUTILSLIB_API AUEUtilsBaseBall : public AActor
{
	GENERATED_BODY()
	
private:
	UEUtilsLogger* logger;
	UStaticMeshComponent* SphereMesh;

public:	
	// Sets default values for this actor's properties
	AUEUtilsBaseBall();
	AUEUtilsBaseBall(const TCHAR*);

	void init(const void* path);

	void EnableGravity(bool enable=true);
	void EnablePhysics(bool enable = true);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
