// Fill out your copyright notice in the Description page of Project Settings.


#include "UEUtilsBaseBall.h"

// Sets default values
AUEUtilsBaseBall::AUEUtilsBaseBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->logger = new UEUtilsLogger(10.0f, FColor::Red);

	this->logger->LOG("Actor Created");

}

// Called when the game starts or when spawned
void AUEUtilsBaseBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUEUtilsBaseBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

