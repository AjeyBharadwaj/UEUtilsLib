// Fill out your copyright notice in the Description page of Project Settings.

#include "UEUtils.h"
#include "Components/DirectionalLightComponent.h"

#include "Math/UnrealMathUtility.h"

UEUtils::UEUtils() {
	this->logger = new UEUtilsLogger(LOGTYPE::ONLY_CONSOLE, 10.0f, FColor::Red);
}

UEUtils::~UEUtils() {

}

AActor* UEUtils::SpawnActor(UWorld *world, UClass *uclass, FVector location, FRotator rotator, FActorSpawnParameters spawnInfo) {
	LOGME("Actor Spawnned");

	return world->SpawnActor<AActor>(uclass, location, rotator, spawnInfo);
}

AActor* UEUtils::SpawnActor(UWorld* world, UClass* uclass, FVector location, FRotator rotator) {
	FActorSpawnParameters spawnInfo;
	spawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	return SpawnActor(world, uclass, location, rotator, spawnInfo);
}

AActor* UEUtils::SpawnActor(UWorld* world, UClass* uclass) {
	return SpawnActor(world, uclass, FVector(0.0f), FRotator(0.0f));
}

AActor* UEUtils::SpawnActorDeffered(UWorld* world, UClass* uclass, FTransform spawnLocAndRotation) {
	LOGME("Actor Spawnned deffered");
	return world->SpawnActorDeferred<AActor>(uclass, spawnLocAndRotation);
}

void UEUtils::SpawnActorDefferedFinish(UWorld* world, AActor *actor, FTransform spawnLocAndRotation) {
	LOGME("Actor Spawnned deffered finshed");
	actor->FinishSpawning(spawnLocAndRotation);
}

float UEUtils::RandomFloat(float min, float max) {
	return FMath::RandRange(min, max);
}

void UEUtils::AddImpulse(UStaticMeshComponent* mesh, FVector Impulse, FName BoneName, bool bVelChange) {
	mesh->AddImpulse(Impulse, BoneName, bVelChange);
}

void UEUtils::SetScale(AActor* actor, FVector scale) {
	actor->SetActorScale3D(scale);
}

void UEUtils::SetMaterial(UStaticMeshComponent* mesh, const TCHAR* material) {
	static ConstructorHelpers::FObjectFinder<UMaterial> FoundMaterial(material);
	if (FoundMaterial.Succeeded())
	{
		LOGME("Setting material");
		UMaterialInstanceDynamic* DynamicMaterialInst = UMaterialInstanceDynamic::Create(FoundMaterial.Object, mesh);
		mesh->SetMaterial(0, DynamicMaterialInst);
	}
}

void UEUtils::SetMassInKg(UStaticMeshComponent* mesh, float mass)
{
	FBodyInstance* BodyInst = mesh->GetBodyInstance();

	if (!BodyInst) return;
	BodyInst->MassScale = mass;

	BodyInst->UpdateMassProperties();
}

// NOTE : Make sure Force No Precomputed Light is Turned On
ADirectionalLight* UEUtils::CreateDirectionalLight(UWorld* world, FVector location, FRotator rotator) {
	LOGME("Creating directional light");
	return (ADirectionalLight *)SpawnActor(world, ADirectionalLight::StaticClass(), location, rotator);
}

void UEUtils::SetAtmosphereSunLight(ADirectionalLight* light, bool value) {
	UDirectionalLightComponent* comp = light->GetComponent();
	if (comp) {
		comp->SetAtmosphereSunLight(value);
	}
}

/* 
 * When PITCH goes beyond 90, YAW and ROLL changes. This is called Gimble Lock
 * To fix it, we should set Quat instead of FRotator
 * More Info : https://www.youtube.com/watch?app=desktop&v=KqbqZ3IY1II
 * More Info : https://pastebin.com/DqBgCUkx
 */
FQuat Euler_To_Quaternion(FRotator Current_Rotation)
{
	FQuat q;                                            // Declare output quaternion
	float yaw = Current_Rotation.Yaw * PI / 180;        // Convert degrees to radians 
	float roll = Current_Rotation.Roll * PI / 180;
	float pitch = Current_Rotation.Pitch * PI / 180;

	double cy = cos(yaw * 0.5);
	double sy = sin(yaw * 0.5);
	double cr = cos(roll * 0.5);
	double sr = sin(roll * 0.5);
	double cp = cos(pitch * 0.5);
	double sp = sin(pitch * 0.5);

	q.W = cy * cr * cp + sy * sr * sp;
	q.X = cy * sr * cp - sy * cr * sp;
	q.Y = cy * cr * sp + sy * sr * cp;
	q.Z = sy * cr * cp - cy * sr * sp;

	return q;                                           // Return the quaternion of the input Euler rotation
}

void UEUtils::AddToSunLocation(ADirectionalLight* light, FRotator rotator) {
	LOGME(Euler_To_Quaternion(rotator).ToString());
	light->AddActorLocalRotation(Euler_To_Quaternion(rotator));
}

void UEUtils::SetSunMobility(ADirectionalLight* light, EComponentMobility::Type mobility) {
	light->SetMobility(mobility);
}