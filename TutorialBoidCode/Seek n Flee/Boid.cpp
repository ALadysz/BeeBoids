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

// Called every frame
void ABoid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABoid::UpdateBoid(float DeltaTime)
{
	FVector targetVelocity = FVector::ZeroVector;
	if (waitCounter > 0)
	{
		waitCounter -= DeltaTime;
	}
	//find velocity
	
	FVector closestBoidPos = Manager->ClosestBoidPosition(this);
	if (Manager->TaggedBoid == this)
	{ //Chaser
		targetVelocity = Seek(closestBoidPos);
		targetVelocity *= Manager->ChaserMultiplier;
	}
	else
	{ //Flee!
		targetVelocity = Flee(closestBoidPos);
	}

	FVector newForce = targetVelocity - currentVelocity;
	currentVelocity += newForce * DeltaTime;

	FVector location = GetActorLocation();
	location += (currentVelocity * Speed * DeltaTime);

	SetActorLocation(location);

}
