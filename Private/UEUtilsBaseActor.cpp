// Fill out your copyright notice in the Description page of Project Settings.


#include "UEUtilsBaseActor.h"

void AUEUtilsBaseActor::init(const void* _path) {
	TCHAR* path = (TCHAR*)_path;
	this->logger = new UEUtilsLogger(LOGTYPE::ONLY_CONSOLE, 10.0f, FColor::Red);

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->logger->LOG("Actor Created");

	this->staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = this->staticMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereMeshAsset(path);
	this->staticMesh->SetStaticMesh(SphereMeshAsset.Object);
}

// Sets default values
AUEUtilsBaseActor::AUEUtilsBaseActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Sets default values
AUEUtilsBaseActor::AUEUtilsBaseActor(const TCHAR* path)
{
	PrimaryActorTick.bCanEverTick = true;	
}

// Called when the game starts or when spawned
void AUEUtilsBaseActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUEUtilsBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUEUtilsBaseActor::EnablePhysics(bool enable) {
	this->staticMesh->SetSimulatePhysics(true);
}

void AUEUtilsBaseActor::EnableGravity(bool enable) {
	this->staticMesh->SetEnableGravity(true);

	//this->SphereMesh->AddImpulse
}

