// Fill out your copyright notice in the Description page of Project Settings.


#include "UEUtilsBaseBall.h"

void AUEUtilsBaseBall::init(const void* _path) {
	TCHAR* path = (TCHAR*)_path;
	this->logger = new UEUtilsLogger(10.0f, FColor::Red);

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->logger->LOG("Actor Created");

	this->SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
	RootComponent = this->SphereMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereMeshAsset(path);
	this->SphereMesh->SetStaticMesh(SphereMeshAsset.Object);
}

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

void AUEUtilsBaseBall::EnablePhysics(bool enable) {
	this->SphereMesh->SetSimulatePhysics(true);
}

void AUEUtilsBaseBall::EnableGravity(bool enable) {
	this->SphereMesh->SetEnableGravity(true);
}

