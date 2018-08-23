// Fill out your copyright notice in the Description page of Project Settings.

#include "SynEnv.h"
#include "AIHumanController.h"
#include "AIHuman.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Navigation/CrowdFollowingComponent.h"

AAIHumanController::AAIHumanController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>(TEXT("PathFollowingComponent")))
{

}


void AAIHumanController::Possess(APawn * Pawn)
{
	Super::Possess(Pawn);

	AAIHuman* AICharacter = Cast<AAIHuman>(Pawn);

	if (AICharacter) {

		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAIHuman::StaticClass(), OtherAI);

	}
}
