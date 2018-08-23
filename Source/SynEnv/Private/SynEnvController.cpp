// Fill out your copyright notice in the Description page of Project Settings.

#include "SynEnv.h"
#include "SynEnvController.h"
#include "AIHuman.h"


// Sets default values
ASynEnvController::ASynEnvController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASynEnvController::BeginPlay()
{
	Super::BeginPlay();
}

void ASynEnvController::Freeze()
{
	if (actors.Num() > 0) {
		for (int i = 0; i < actors.Num(); i++)
		{
			if (actors[i] && actors[i]->IsValidLowLevel()) {
				TArray<USkeletalMeshComponent *> USkeletalMeshComponents;
				bool b = actors[i]->IsValidLowLevel();
				bool bb = actors[i]->IsPendingKill();
				actors[i]->GetComponents<USkeletalMeshComponent>(USkeletalMeshComponents);
				USkeletalMeshComponent* StaticMeshComponent = USkeletalMeshComponents[0];
				StaticMeshComponent->GlobalAnimRateScale = 0.0f;
				TArray<UCharacterMovementComponent *> UCharacterMovementComponents;
				actors[i]->GetComponents<UCharacterMovementComponent>(UCharacterMovementComponents);
				UCharacterMovementComponent* UCharacterMovementComponent = UCharacterMovementComponents[0];
				UCharacterMovementComponent->SetActive(false);
			}
			else {
				int x = 1;
			}
		}
	}
}


void ASynEnvController::Defrost()
{
	if (actors.Num() > 0) {
		for (int i = 0; i < actors.Num(); i++)
		{
			if (actors[i] && actors[i]->IsValidLowLevel()) {
				TArray<USkeletalMeshComponent *> USkeletalMeshComponents;
				bool b = actors[i]->IsValidLowLevel();
				bool bb = actors[i]->IsPendingKill();
				actors[i]->GetComponents<USkeletalMeshComponent>(USkeletalMeshComponents);
				USkeletalMeshComponent* StaticMeshComponent = USkeletalMeshComponents[0];
				StaticMeshComponent->GlobalAnimRateScale = 1.0f;
				TArray<UCharacterMovementComponent *> UCharacterMovementComponents;
				actors[i]->GetComponents<UCharacterMovementComponent>(UCharacterMovementComponents);
				UCharacterMovementComponent* UCharacterMovementComponent = UCharacterMovementComponents[0];
				UCharacterMovementComponent->SetActive(true);
			}
			else {
				int x = 1;
			}
		}
	}
}

void ASynEnvController::SpawnAI() {

	if (actors.Num() > 0) {
		for (int i = 0; i < actors.Num(); i++)
		{
			if (!actors[i]) continue;
			if (!actors[i]->IsValidLowLevel()) continue;
			//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

			actors[i]->K2_DestroyActor();
			actors[i] = NULL;
		}

		actors.Empty();

		//GC
		GetWorld()->ForceGarbageCollection(true);
	}


	FActorSpawnParameters spawnParams;

	spawnParams.Owner = this;

	FVector coordinate;

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Ready to spawn AI."));

	if (IsSingleAI) {

		coordinate.X = 600;
		coordinate.Y = 160;
		coordinate.Z = 218;

		for (int i = 0; i < 1; i++) {
			AActor* AI = GetWorld()->SpawnActor<AAIHuman>(AICharacter[0], coordinate, FRotator::ZeroRotator, spawnParams);
			if (AI) {
				FRotator ActorRotation = AI->GetActorRotation();
				ActorRotation.Yaw = 180;
				AI->SetActorRotation(ActorRotation);

				actors.Add(AI);
			}
		}
	}
	else 
	{
		for (int i = 0; i < NumberOfAI; i++) {
			coordinate.X = FMath::RandRange(600, 1650);
			coordinate.Y = FMath::RandRange(-50, 340);
			coordinate.Z = 218;

			int index = i % AICharacter.Num();

			AActor* AI = GetWorld()->SpawnActor<AAIHuman>(AICharacter[index], coordinate, FRotator::ZeroRotator, spawnParams);
			if (AI) {
				FRotator ActorRotation = AI->GetActorRotation();
				ActorRotation.Yaw = 180;
				AI->SetActorRotation(ActorRotation);

				actors.Add(AI);
			}
		}
	}
}

// Called every frame
void ASynEnvController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

