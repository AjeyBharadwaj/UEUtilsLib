// Fill out your copyright notice in the Description page of Project Settings.


#include "UEUtilsSky.h"
#include "UEUtils.h"

// Sets default values
AUEUtilsSky::AUEUtilsSky()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUEUtilsSky::BeginPlay()
{
	LOG("Begin Play");
	AActor::BeginPlay();

	ueutils = new UEUtils();

	light = ueutils->CreateDirectionalLight(GetWorld(), FVector(410, 80, 170), FRotator(-0.0, 0.0, 0.0));

	ueutils->SetAtmosphereSunLight(light, true);
	ueutils->SetSunMobility(light, EComponentMobility::Movable);
	
}

// Called every frame
void AUEUtilsSky::Tick(float DeltaTime)
{
	AActor::Tick(DeltaTime);

	static float defaultPositionIncrementor = 0.2;
	static float positionIncrementor = -defaultPositionIncrementor;

	ueutils->AddToSunLocation(light, FRotator(positionIncrementor, 0, 0));// light->GetActorRotation().Add(5, 0, 0));

	if (light->GetActorRotation().Pitch > 5) {
		positionIncrementor *= -1;
		ueutils->AddToSunLocation(light, FRotator(positionIncrementor, 0, 0));
	}

}

