// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoidManager.generated.h"

UCLASS()
class CT5108ASSIGNMNET_API ABoidManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoidManager();
	
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Settings")
	int SpawnCount = 30;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	float SpawnRadius = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	float NeighbourRadius = 900;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	float SeperationWeight = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	float CohesionWeight = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	float AlignmentWeight = 1;

	USceneComponent* transform;

	TArray<class ABoid*> MyBoids;

protected:
	// Called when the game starts or when spawned
	//spawn boids
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//update boids
	virtual void Tick(float DeltaTime) override;
	TArray<class ABoid*> GetBoidNeighbourHood(ABoid* thisBoid);

};
