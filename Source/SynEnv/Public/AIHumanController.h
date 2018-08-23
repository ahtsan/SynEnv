// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "AIHumanController.generated.h"

/**
 * 
 */
UCLASS()
class SYNENV_API AAIHumanController : public AAIController
{
	GENERATED_BODY()

	TArray<AActor*> OtherAI;

	virtual void Possess(APawn* Pawn) override;

	UPROPERTY(EditAnywhere, Category = AI)
	int DetectRadius;
public:

	AAIHumanController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
	FORCEINLINE TArray<AActor*> GetOtherAI() const { return OtherAI; }
};
