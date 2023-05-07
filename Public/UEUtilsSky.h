// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UEUtils.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UEUtilsLib/Public/UEUtilsLogger.h"
#include "Engine/DirectionalLight.h"

#include "UEUtilsSky.generated.h"

UCLASS()
class UEUTILSLIB_API AUEUtilsSky : public AActor, public UEUtilsLogger
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUEUtilsSky();
	ADirectionalLight* light;
	UEUtils* ueutils;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
