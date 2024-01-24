
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Boid.generated.h"


UCLASS()
class CT5108ASSIGNMNET_API ABoid : public AActor
{
	GENERATED_BODY()

public:
	ABoid();

	//velocity initially set to nothing
	FVector currentVelocity = FVector::ZeroVector;

	//reference to manager
	class ABoidManager* Manager;

	//placeholder speed value - yoinked from manager
	float Speed = 100; 

	//needed for chaser to know when they should start chasing again
	float waitCounter = 0;


	//mesh
	UStaticMeshComponent* Mesh;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	//chasing behaviour functions
	FVector Seek(FVector position);
	FVector Flee(FVector position);

	//flocking behaviour functions
	FVector Alignment(TArray<ABoid*> Neighbours);
	FVector Cohesion(TArray<ABoid*> Neighbours);
	FVector Seperation(TArray<ABoid*> Neighbours);

	//function that calculates how strongly it should be yeeted to the center
	FVector CenterForce(const FVector& currentPos);
	//function that throws the boid back towards the center
	void YeetBackIn(FVector boidPosition, FVector targetVelocity, float DeltaTime);

	//boundary values
	float boundary_min_x = 500, boundary_min_y = 500, boundary_min_z = 500;
	float boundary_max_x = 5500, boundary_max_y = 5500, boundary_max_z = 5500;

	//center point of boundary
	FVector center = FVector(
            (boundary_min_x + boundary_max_x) * 0.5f,
            (boundary_min_y + boundary_max_y) * 0.5f,
            (boundary_min_z + boundary_max_z) * 0.5f
        );



	void OnMeshLoaded();

	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//flocking behaviour that happens on tick
	void UpdateFlockBoid(float DeltaTime);
	//seek + flee behaviour that happens on tick
	void UpdateFleeBoid(float DeltaTime);


};
