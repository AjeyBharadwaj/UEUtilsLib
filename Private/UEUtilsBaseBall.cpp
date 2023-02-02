// Fill out your copyright notice in the Description page of Project Settings.


#include "UEUtilsBaseBall.h"


// Sets default values
AUEUtilsBaseBall::AUEUtilsBaseBall()
{
	init(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
}

AUEUtilsBaseBall::AUEUtilsBaseBall(const TCHAR* path)
{
	init(path);
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

