// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Boid.generated.h"


UCLASS()
class CT5108ASSIGNMNET_API ABoid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoid();

	FVector currentVelocity = FVector::ZeroVector;

	class ABoidManager* Manager;

	float Speed = 100;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FVector Seek(FVector position);
	FVector Flee(FVector position);

	FVector Alignment(TArray<ABoid*> Neighbours);
	FVector Cohesion(TArray<ABoid*> Neighbours);
	FVector Seperation(TArray<ABoid*> Neighbours);


	UStaticMeshComponent* Mesh;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void UpdateBoid(float DeltaTime);

};
