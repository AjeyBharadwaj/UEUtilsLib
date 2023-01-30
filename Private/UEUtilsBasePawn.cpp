// Fill out your copyright notice in the Description page of Project Settings.

#include "UEUtils.h"
#include "UEUtilsBaseBall.h"

#include "UEUtilsBasePawn.h"

// Sets default values
AUEUtilsBasePawn::AUEUtilsBasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->logger = new UEUtilsLogger(10.0f, FColor::Red);

	this->logger->LOG("PAWN Created");


	this->cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	RootComponent = this->cameraComponent;
	this->cameraComponent->bUsePawnControlRotation = true;

	/*
	this->cameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	this->cameraBoom->SetupAttachment(RootComponent);
	this->cameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	this->cameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	this->cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	this->cameraComponent->SetupAttachment(this->cameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	this->cameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
	*/

	//UEUtils::SpawnActor<AUEUtilsBaseBall>(GetWorld());
	//UEUtils::SpawnActor(GetWorld(), AUEUtilsBaseBall::StaticClass());
	

}

// Called when the game starts or when spawned
void AUEUtilsBasePawn::BeginPlay()
{
	Super::BeginPlay();
	this->logger->LOG("Begine Play");

	FVector Location(100.0f, -150.0f, 30.0f);
	FRotator Rotator(0.0f, 0.0f, 0.0f);

	UEUtils::SpawnActor(GetWorld(), AUEUtilsBaseBall::StaticClass(), Location, Rotator);

	this->logger->LOG("Tried to spawn Created");

	Location.Y = 100.0f;
	UEUtils::SpawnActor(GetWorld(), AUEUtilsBaseBall::StaticClass(), Location, Rotator);
}

// Called every frame
void AUEUtilsBasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUEUtilsBasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

