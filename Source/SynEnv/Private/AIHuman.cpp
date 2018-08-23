// Fill out your copyright notice in the Description page of Project Settings.

#include "SynEnv.h"
#include "AIHuman.h"
#include "AIHumanController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/PawnSensingComponent.h"

// Sets default values
AAIHuman::AAIHuman()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));

	id = 0;
}

// Called when the game starts or when spawned
void AAIHuman::BeginPlay()
{
	Super::BeginPlay();
	
	if (PawnSensingComp) {
		PawnSensingComp->OnSeePawn.AddDynamic(this, &AAIHuman::OnPlayerDetected);
	}
}

// Called every frame
void AAIHuman::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AAIHuman::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void AAIHuman::OnPlayerDetected(APawn * Pawn)
{
	AAIHumanController* AIController = Cast<AAIHumanController>(GetController());

	//if (AIController) {
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You are detected."));
	//}
}
