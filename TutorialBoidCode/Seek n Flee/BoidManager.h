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
	int MaxFleeDistance = 9000;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	int CatchRange = 100;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	int ChaserMultiplier = 2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	float TimeoutTime = 5.0f;

	USceneComponent* transform;

	TArray<class ABoid*> MyBoids;
	class ABoid* lastTagged;
	class ABoid* TaggedBoid;
protected:
	// Called when the game starts or when spawned
	//spawn boids
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//update boids
	virtual void Tick(float DeltaTime) override;
	FVector ClosestBoidPosition(ABoid* thisBoid);

};
