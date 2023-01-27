// Fill out your copyright notice in the Description page of Project Settings.

#include "UEUtilsLogger.h"
#include "Engine.h"

UEUtilsLogger::UEUtilsLogger(float time, FColor color)
{
	this->time = time;
	this->color = color;
}

UEUtilsLogger::~UEUtilsLogger()
{
}

void UEUtilsLogger::LOG(FString msg) {
	if (GEngine) { 
		GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Yellow, msg); 
	}
}
