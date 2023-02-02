// Fill out your copyright notice in the Description page of Project Settings.

#include "UEUtilsLogger.h"
#include "Engine.h"

UEUtilsLogger::UEUtilsLogger(LOGTYPE logtype, float time, FColor color)
{
	this->logtype = logtype;
	this->time = time;
	this->color = color;
}

UEUtilsLogger::~UEUtilsLogger()
{
}

void UEUtilsLogger::LOG(FString msg, FString func, int line) {
	if (this->logtype == LOGTYPE::ONLY_SCREEN || this->logtype == LOGTYPE::SCREEN_AND_CONSOLE) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, this->time, this->color, msg);
		}
	}

	if (this->logtype == LOGTYPE::ONLY_CONSOLE || this->logtype == LOGTYPE::SCREEN_AND_CONSOLE) {
		if (func.Len() == 0) {
			UE_LOG(LogTemp, Error, TEXT("%s"), *msg);
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("%s:%d : %s"), *func, __LINE__, *msg);
		}
	}
}
