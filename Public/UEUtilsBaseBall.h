// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "UEUtilsLogger.h"
#include "UEUtilsBaseActor.h"

#include "UEUtilsBaseBall.generated.h"

UCLASS()
class UEUTILSLIB_API AUEUtilsBaseBall : public AUEUtilsBaseActor
{
	GENERATED_BODY()
	
private:
	UEUtilsLogger* logger;

public:	
	// Sets default values for this actor's properties
	AUEUtilsBaseBall();
	AUEUtilsBaseBall(const TCHAR*);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
