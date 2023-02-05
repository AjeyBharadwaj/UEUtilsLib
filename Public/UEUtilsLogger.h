// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#define LOGME(msg) this->logger->LOG(msg, __FUNCTION__, __LINE__)

enum LOGTYPE {
	ONLY_SCREEN,
	ONLY_CONSOLE,
	SCREEN_AND_CONSOLE,
};

/**
 * 
 */
class UEUTILSLIB_API UEUtilsLogger
{
private:
	LOGTYPE logtype;
	FColor color;
	float time;

public:
	UEUtilsLogger(LOGTYPE logtype = LOGTYPE::ONLY_CONSOLE, float time=10.0f, FColor color=FColor::Red);
	~UEUtilsLogger();

	inline void LOG(FString msg, FString func="", int line = -1);
};
