
#include "Boid.h"
#include "BoidManager.h"

// Sets default values
ABoid::ABoid()
{
    PrimaryActorTick.bCanEverTick = true;

    //creating mesh + attaching
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("bee"));
    Mesh->SetCollisionProfileName(TEXT("BlockAll"));
    Mesh->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));

    //yoinking bee from files
    static ConstructorHelpers::FObjectFinder<UStaticMesh> BeeMeshAsset(TEXT("/Game/Models/bee"));
	//if the bee is found + mesh exists
    if (Mesh && BeeMeshAsset.Succeeded())
    {
		//set mesh
        Mesh->SetStaticMesh(BeeMeshAsset.Object);
    }
    else
    {
		//if not found output error log
        UE_LOG(LogTemp, Error, TEXT("Failed to load bee mesh or Mesh is null!"));
    }
    // set root component
    SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ABoid::BeginPlay()
{
	Super::BeginPlay();
}

//seek logic
FVector ABoid::Seek(FVector position)
{
	FVector newVelocity = position - GetActorLocation();
	newVelocity.Normalize();
	return newVelocity;
}

//flee logic
FVector ABoid::Flee(FVector position)
{
	FVector newVelocity = GetActorLocation() - position;
	newVelocity.Normalize();
	return newVelocity;
}

//allignmnet logic
FVector ABoid::Alignment(TArray<ABoid*> Neighbours)
{
	if (Neighbours.Num() == 0) return FVector::ZeroVector;
	FVector newVelocity;
	for (ABoid* Boid : Neighbours)
	{
		newVelocity += Boid->currentVelocity;
	}
	newVelocity /= Neighbours.Num();
	newVelocity.Normalize();

	return newVelocity;
}

//cohesion logic
FVector ABoid::Cohesion(TArray<ABoid*> Neighbours)
{
	if (Neighbours.Num() == 0) return FVector::ZeroVector;
	FVector avgLocation;
	float inverseVal = 1 / Neighbours.Num();
	for (ABoid* Boid : Neighbours)
	{
		avgLocation += (Boid->GetActorLocation() * inverseVal);
	}


	return Seek(avgLocation);
}

//separation logic
FVector ABoid::Seperation(TArray<ABoid*> Neighbours)
{
	if (Neighbours.Num() == 0) return FVector::ZeroVector;
	FVector avgFlee;
	//float inverseVal = 1 / Neighbours.Num();
	for (ABoid* Boid : Neighbours)
	{
		avgFlee += Flee(Boid->GetActorLocation());
	}


	avgFlee.Normalize();

	return avgFlee;
}

// Called every frame
void ABoid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


FVector ABoid::CenterForce(const FVector& currentPos)
{
	//calculate direction to center
    FVector directionToCenter = center - currentPos;
    directionToCenter.Normalize();

	//how strongly they get thrown back to the center
    float centeringForceStrength = 5.0f;
	//calculate center force	
    FVector centerForce = directionToCenter * centeringForceStrength;

    return centerForce;
}

void ABoid::YeetBackIn(FVector boidPosition, FVector targetVelocity, float DeltaTime)
{
	//calculate target velocity
    targetVelocity = (center - boidPosition).GetSafeNormal() * Manager->BoidSpeed;

	//get centerforce from function
	FVector centerForce = CenterForce(boidPosition);
		
	//combine
	FVector totalForce = targetVelocity - currentVelocity + centerForce;

	// update current velocity
	currentVelocity += totalForce * DeltaTime;

	//update position
	FVector location = GetActorLocation();
	location += currentVelocity * Manager->BoidSpeed * DeltaTime;
	SetActorLocation(location);
}

void ABoid::UpdateFlockBoid(float DeltaTime)
{
	//get boid ppos
	FVector boidPosition = GetActorLocation();
	//reset target velocity
	FVector targetVelocity = FVector::ZeroVector;
	//get neighbourhood
	TArray<ABoid*> closestBoids = Manager->GetBoidNeighbourHood(this);

	//if the boid is tryna leave the boundary
	if(boidPosition.X < boundary_min_x || boidPosition.X > boundary_max_x ||
		boidPosition.Y < boundary_min_y ||boidPosition.Y > boundary_max_y ||
		boidPosition.Z < boundary_min_x || boidPosition.Y > boundary_max_z )
	{ 		
		//throw it back in
		YeetBackIn(boidPosition, targetVelocity, DeltaTime);
	}
	else
	{
		//otherwise do flocking logic
		//modify target velocity according to variables
		targetVelocity += Seperation(closestBoids) * Manager->SeperationWeight;
		targetVelocity += Cohesion(closestBoids) * Manager->CohesionWeight;
		targetVelocity += Alignment(closestBoids) * Manager->AlignmentWeight;

		//make the bees do funky circles
		//reset variable
		FVector boidToCenter = FVector::ZeroVector; 

		//calculate average direction
		for (ABoid* CloseBoid : closestBoids)
		{
			boidToCenter += CloseBoid->GetActorLocation() - GetActorLocation();
		}
		
		// rotate 90 degrees
		FVector curvatureForce = FVector(-boidToCenter.Y, boidToCenter.X, 0.0f);  
		curvatureForce.Normalize();
		//add by curvature strength
		curvatureForce *= Manager->CurvatureStrength;

		//add curvature
		targetVelocity += curvatureForce;
		targetVelocity.Normalize();

		//calculate
		FVector newForce = targetVelocity - currentVelocity;
		currentVelocity += newForce * DeltaTime;

		//get new position according to previous calculations
		boidPosition += (currentVelocity * Manager->BoidSpeed * DeltaTime);

		//set location
		SetActorLocation(boidPosition);
	}

	//make bee look the way its going
	FRotator NewRotation = currentVelocity.Rotation();
	SetActorRotation(NewRotation);
}

void ABoid::UpdateFleeBoid(float DeltaTime)
{
	//reset target velocity
	FVector targetVelocity = FVector::ZeroVector;
	//set boid pos to current location
	FVector boidPosition = GetActorLocation();
	//if bee out of bounds
	if(boidPosition.X < boundary_min_x || boidPosition.X > boundary_max_x ||
		boidPosition.Y < boundary_min_y ||boidPosition.Y > boundary_max_y ||
		boidPosition.Z < boundary_min_x || boidPosition.Y > boundary_max_z )
	{	
		//throw it back in
		YeetBackIn(boidPosition, targetVelocity, DeltaTime);
	}
	else
	{
		//set waitCounter
		if (waitCounter > 0)
		{
			waitCounter -= DeltaTime;
		}

		//find closest boid
		FVector closestBoidPos = Manager->ClosestBoidPosition(this);
		if (Manager->TaggedBoid == this)
		{ 
			//angry bee logic (chaser)
			targetVelocity = Seek(closestBoidPos);
			targetVelocity *= Manager->ChaserMultiplier;
		}
		else
		{ 
			//scared bee logic (flee)
			targetVelocity = Flee(closestBoidPos);
		}

		//find velocity
		FVector newForce = targetVelocity - currentVelocity;
		currentVelocity += newForce * DeltaTime;

		//find location
		FVector location = GetActorLocation();
		location += (currentVelocity * Manager->BoidSpeed * DeltaTime);

		//set  location
		SetActorLocation(location);
	}

	//look the way its going
	FRotator NewRotation = currentVelocity.Rotation();
		SetActorRotation(NewRotation);


}