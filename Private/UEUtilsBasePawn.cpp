// Fill out your copyright notice in the Description page of Project Settings.

#include "UEUtilsBasePawn.h"

#include "UEUtils.h"
#include "UEUtilsBaseBall.h"

// Sets default values
AUEUtilsBasePawn::AUEUtilsBasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->logger = new UEUtilsLogger(LOGTYPE::ONLY_CONSOLE, 10.0f, FColor::Red);

	LOGME("PAWN Created");

	ueutils = new UEUtils();


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

	//ueutils->SpawnActor<AUEUtilsBaseBall>(GetWorld());
	//ueutils->SpawnActor(GetWorld(), AUEUtilsBaseBall::StaticClass());
	

}

// Called when the game starts or when spawned
void AUEUtilsBasePawn::BeginPlay()
{
	Super::BeginPlay();
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
	PlayerInputComponent->BindAction("ButtonPressed", IE_Pressed, this, &AUEUtilsBasePawn::ButtonPressed);

}

void AUEUtilsBasePawn::ButtonPressed() {
	int i = 2;

	Super::BeginPlay();

	if (i == 0) {
		LOGME("Begine Play");

		FVector Location(100.0f, -150.0f, 30.0f);
		FRotator Rotator(0.0f, 0.0f, 0.0f);

		ueutils->SpawnActor(GetWorld(), AUEUtilsBaseBall::StaticClass(), Location, Rotator);

		LOGME("Tried to spawn Created");

		Location.Y = 100.0f;
		ueutils->SpawnActor(GetWorld(), AUEUtilsBaseBall::StaticClass(), Location, Rotator);
	}
	else if (i == 1) {
		FTransform spawnLocAndRotation;

		spawnLocAndRotation.SetLocation(FVector(ueutils->RandomFloat(-100.0f, 100.0f), ueutils->RandomFloat(-150.0f, -100.0f), ueutils->RandomFloat(300.0f, 400.0f)));

		AUEUtilsBaseBall*actor = (AUEUtilsBaseBall *)ueutils->SpawnActorDeffered(GetWorld(), AUEUtilsBaseBall::StaticClass(), spawnLocAndRotation);
		ueutils->SpawnActorDefferedFinish(GetWorld(), actor, spawnLocAndRotation);

		actor->EnablePhysics();
		actor->EnableGravity();
	}

	else if (i == 2) {
		FTransform spawnLocAndRotation;

		spawnLocAndRotation.SetLocation(FVector(150.0f, 350, 250));

		AUEUtilsBaseBall* actor = (AUEUtilsBaseBall*)ueutils->SpawnActorDeffered(GetWorld(), AUEUtilsBaseBall::StaticClass(), spawnLocAndRotation);
		ueutils->SpawnActorDefferedFinish(GetWorld(), actor, spawnLocAndRotation);

		ueutils->SetScale(actor, FVector(.3, .3, .3));

		actor->EnablePhysics();
		//actor->EnableGravity();

		ueutils->AddImpulse(actor->getStaticMeshComponent(), FVector(0.0f, -1000.0f, 0.0f), "NONE", true);


		ueutils->SetMassInKg(actor->getStaticMeshComponent(), 10);
	}
}

