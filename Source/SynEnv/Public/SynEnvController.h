// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SynEnvController.generated.h"

UCLASS()
class SYNENV_API ASynEnvController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASynEnvController();

	TArray<AActor*> actors;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = AI)
	void SpawnAI();

	UFUNCTION(BlueprintCallable, Category = AI)
	void Freeze();

	UFUNCTION(BlueprintCallable, Category = AI)
	void Defrost();

	UPROPERTY(EditAnywhere, Category = AI)
	int NumberOfAI;

	UPROPERTY(EditAnywhere, Category = AI)
	bool IsSingleAI;

	UPROPERTY(EditAnywhere, Category = AI)
	TArray<TSubclassOf<AActor>> AICharacter;
	
};
