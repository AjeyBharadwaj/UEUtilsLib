// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class UEUTILSLIB_API UEUtilsLogger
{
private:
	FColor color;
	float time;

public:
	UEUtilsLogger(float time, FColor color);
	~UEUtilsLogger();

	void LOG(FString msg);
};
