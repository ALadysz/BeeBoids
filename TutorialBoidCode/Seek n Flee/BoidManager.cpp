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
		FVector SpawnLocation = (FMath::VRand()* SpawnRadius) + GetActorLocation();
		FRotator SpawnRotation = GetActorRotation();

		ABoid* newboid = GetWorld()->SpawnActor<ABoid>(SpawnLocation, SpawnRotation);
		newboid -> Manager = this;
		MyBoids.Add(newboid);
	}
	TaggedBoid = MyBoids[0];
	TaggedBoid->Speed = 500;
}

// Called every frame
void ABoidManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	for(ABoid* Boid : MyBoids)
	{
		//Boid->UpdateBoid(DeltaTime);
	}

}

FVector ABoidManager::ClosestBoidPosition(ABoid* thisBoid)
{
	float ClosestDistance = MaxFleeDistance;
	FVector returnVal = GetActorLocation();

	for(ABoid* Boid : MyBoids) 
	{
		if (Boid == thisBoid || !Boid || Boid == lastTagged)
		{
			continue;
		}
		float aDistance = (Boid -> GetActorLocation() - thisBoid -> GetActorLocation()).Size();
		if(aDistance < ClosestDistance)
		{
			ClosestDistance = aDistance;
			returnVal = Boid -> GetActorLocation();
		}

		if (thisBoid == TaggedBoid)
		{
			if (ClosestDistance < CatchRange)
			{ //tag new boid
				lastTagged = TaggedBoid;
				TaggedBoid = Boid;
				TaggedBoid->waitCounter = TimeoutTime;
				
			}
		}

	
	}
	
    return returnVal;
}



