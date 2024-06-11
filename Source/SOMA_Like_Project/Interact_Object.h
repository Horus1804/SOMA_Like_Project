// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyInterface.h"
#include "Interact_Object.generated.h"


UCLASS(BlueprintType, Category="MyGame")
class SOMA_LIKE_PROJECT_API AInteract_Object : public AActor, public IMyInterface
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Mesh")
	UStaticMeshComponent* Mesh;
	
public:	
	// Sets default values for this actor's properties
	AInteract_Object();
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Blueprint Native Event override
	virtual bool ReactToTrigger_Implementation() override;
	virtual void TestInterfaceCall_Implementation() override;

	UFUNCTION()
	void TestCallDelegate(bool isGrabbed);
};
