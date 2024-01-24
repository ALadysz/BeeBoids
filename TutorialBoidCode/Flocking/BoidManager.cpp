// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidManager.h"
#include "Boid.h"

// Sets default values
ABoidManager::ABoidManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	transform = CreateDefaultSubobject<USceneComponent>("RootSceneComponent");
	this -> SetRootComponent(transform);
}

// Called when the game starts or when spawned
void ABoidManager::BeginPlay()
{
	Super::BeginPlay();
	
	for(int i = 0; i < SpawnCount; i++)
	{
		if (SpawnRadius <= 0.0f)
		{
    		UE_LOG(LogTemp, Warning, TEXT("SpawnRadius is not properly initialized or has an invalid value!"));
		}
		else
		{
    		FVector SpawnLocation = (FMath::VRand() * SpawnRadius) + GetActorLocation();
		}
		FVector SpawnLocation = (FMath::VRand()* FMath::RandRange(0.0f, SpawnRadius)) + GetActorLocation();
		FRotator SpawnRotation = GetActorRotation();

		ABoid* newboid = GetWorld()->SpawnActor<ABoid>(SpawnLocation, SpawnRotation);
		newboid -> Manager = this;
		MyBoids.Add(newboid);
	}
}

// Called every frame
void ABoidManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	for(ABoid* Boid : MyBoids)
	{
		Boid->UpdateBoid(DeltaTime);
	}

}

TArray<class ABoid *> ABoidManager::GetBoidNeighbourHood(ABoid *thisBoid)
{
	TArray<class ABoid *> ReturnBoids;

	for(ABoid* Boid : MyBoids) 
	{
		if (Boid == thisBoid || !Boid) continue;
		
		float aDistance = (Boid -> GetActorLocation() - thisBoid -> GetActorLocation()).Size();
		if(aDistance < NeighbourRadius)
		{
			ReturnBoids.Add(Boid);
		}
	
	
	}
	
    return ReturnBoids;
}





