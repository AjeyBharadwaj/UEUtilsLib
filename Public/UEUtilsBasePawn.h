// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "UEUtilsLogger.h"

#include "UEUtilsBasePawn.generated.h"

UCLASS()
class UEUTILSLIB_API AUEUtilsBasePawn : public APawn
{
	GENERATED_BODY()

private:
	UEUtilsLogger *logger;
	UCameraComponent* cameraComponent;
	USpringArmComponent* cameraBoom;

public:
	// Sets default values for this pawn's properties
	AUEUtilsBasePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
