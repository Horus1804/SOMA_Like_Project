// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "MyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UMyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SOMA_LIKE_PROJECT_API IMyInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	/* A version of the React To Trigger function that can be implemented in C++ or Blueprint. */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool ReactToTrigger();

	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void TestInterfaceCall();
};
