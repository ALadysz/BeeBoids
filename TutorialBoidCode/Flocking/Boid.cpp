// Fill out your copyright notice in the Description page of Project Settings.


#include "Boid.h"
#include "BoidManager.h"
// Sets default values
ABoid::ABoid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//mesh creation + attachment
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	UStaticMesh* sphereMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'")).Object;
	
	Mesh -> SetStaticMesh(sphereMesh);
	this -> SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ABoid::BeginPlay()
{
	Super::BeginPlay();
	
}

FVector ABoid::Seek(FVector position)
{
	FVector newVelocity = position - GetActorLocation();
	newVelocity.Normalize();
    return newVelocity;
}

FVector ABoid::Flee(FVector position)
{
	FVector newVelocity = GetActorLocation() - position;
	newVelocity.Normalize();
    return newVelocity;
}

FVector ABoid::Alignment(TArray<ABoid*> Neighbours)
{
	if(Neighbours.Num() == 0) return FVector::ZeroVector;
	FVector newVelocity;
	for (ABoid* Boid : Neighbours)
	{
		newVelocity += Boid->currentVelocity;
	}
	newVelocity /= Neighbours.Num();
	newVelocity.Normalize();

	return newVelocity;
}

FVector ABoid::Cohesion(TArray<ABoid *> Neighbours)
{
    if(Neighbours.Num() == 0) return FVector::ZeroVector;
	FVector avgLocation;
	float inverseVal = 1 / Neighbours.Num();
	for (ABoid* Boid : Neighbours)
	{
		avgLocation += (Boid->GetActorLocation() * inverseVal);
	}


	return Seek(avgLocation);
}

FVector ABoid::Seperation(TArray<ABoid *> Neighbours)
{
    if(Neighbours.Num() == 0) return FVector::ZeroVector;
	FVector avgFlee;
	//float inverseVal = 1 / Neighbours.Num();
	for (ABoid* Boid : Neighbours)
	{
		avgFlee += Flee(Boid->GetActorLocation());
	}


	avgFlee.Normalize();

	return avgFlee;
}



// FVector ABoid::ClosestBoidPosition()
// {
//  	float ClosestDistance = 9000000;
// 	for(ABoid* Boid : ABoidManager::MyBoids) 
// 	{
// 		if (Boid == this || Boid == ABoidManager::lastTagged)
// 		{
// 			continue;
// 		}
// 	}
//     return FVector();
// }

// Called every frame
void ABoid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABoid::UpdateBoid(float DeltaTime)
{
	FVector targetVelocity = FVector::ZeroVector;

	//find velocity
	
	TArray<ABoid*> closestBoids = Manager->GetBoidNeighbourHood(this);

	targetVelocity += Seperation(closestBoids) * Manager->SeperationWeight;;
	targetVelocity += Cohesion(closestBoids) * Manager->CohesionWeight;
	targetVelocity += Alignment(closestBoids) * Manager->AlignmentWeight;;

	targetVelocity.Normalize();

	FVector newForce = targetVelocity - currentVelocity;
	currentVelocity += newForce * DeltaTime;

	FVector location = GetActorLocation();
	location += (currentVelocity * Speed * DeltaTime);

	SetActorLocation(location);

}
