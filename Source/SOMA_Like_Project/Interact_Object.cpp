// Fill out your copyright notice in the Description page of Project Settings.


#include "Interact_Object.h"
#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AInteract_Object::AInteract_Object()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Patrick"));
	SetRootComponent(Mesh);
	Mesh->SetSimulatePhysics(true);
	Mesh->SetEnableGravity(true);
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInteract_Object::BeginPlay()
{
	Super::BeginPlay();
	if(AMyCharacter* PlayerRef = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(this,0)))
	{
		UE_LOG(LogTemp,Warning,TEXT("TESTREFPLAYER"));
		PlayerRef->OnGrabbedObjectDelegate.AddDynamic(this,&AInteract_Object::TestCallDelegate);
	}
}

// Called every frame
void AInteract_Object::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AInteract_Object::ReactToTrigger_Implementation()
{
	UE_LOG(LogTemp,Warning,TEXT("COUCOU"));
	return false;
}

void AInteract_Object::TestInterfaceCall_Implementation()
{
	UE_LOG(LogTemp,Warning,TEXT("TESTINTERFACECALL"));
}

void AInteract_Object::TestCallDelegate(bool isGrabbed)
{
	UE_LOG(LogTemp,Warning,TEXT("%hhd"),isGrabbed);
}

