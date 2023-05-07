	// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UEUtilsLogger.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "UEUtilsCharacterCamera.generated.h"

UCLASS()
class UEUTILSLIB_API AUEUtilsCharacterCamera : public ACharacter, public UEUtilsLogger
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AUEUtilsCharacterCamera();
	class USpringArmComponent* CameraBoom;
	class UCameraComponent* FollowCamera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
