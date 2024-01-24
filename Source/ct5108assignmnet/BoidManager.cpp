
#include "BoidManager.h"
#include "Boid.h"
#include "DrawDebugHelpers.h"

// Sets default values
ABoidManager::ABoidManager()
{
	//create boidmanager
	PrimaryActorTick.bCanEverTick = true;
	transform = CreateDefaultSubobject<USceneComponent>("RootSceneComponent");
	this->SetRootComponent(transform);
	
}

// Called when the game starts or when spawned
void ABoidManager::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < SpawnCount; i++)
	{
		if (SpawnRadius <= 0.0f)
		{
			//if spawn radius is less than or 0 return error
			UE_LOG(LogTemp, Warning, TEXT("SpawnRadius is not properly initialized or has an invalid value!"));
		}
		else
		{
			//set spawn location + rotation
			FVector SpawnLocation = (FMath::VRand() * FMath::RandRange(0.0f, SpawnRadius)) + GetActorLocation();
            FRotator SpawnRotation = GetActorRotation();

			//spawn a boid
            ABoid* newboid = GetWorld()->SpawnActor<ABoid>(ABoid::StaticClass(), SpawnLocation, SpawnRotation);
            
            if (newboid)
            {
				//if created succesfully - set manager and add to boid list
                newboid->Manager = this;
				//at the start give every boid its material
				newboid->Mesh->SetMaterial(0, BoidMaterial);
                MyBoids.Add(newboid);
            }
            else
            {
				//if it doesn't - return error message
               UE_LOG(LogTemp, Error, TEXT("Failed to spawn a new boid."));
            }
		}
	}

	//set tagged boid to the first boid
	TaggedBoid = MyBoids[0];
}

// Called every frame
void ABoidManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//create debug cube
    DrawDebugBox(GetWorld(), CubeCenter, CubeExtent, FQuat::Identity, CubeColor);
	//run whatever current behaviour is selected
	BoidBehaviour(CurrentBehaviour, DeltaTime);	
}

TArray<class ABoid*> ABoidManager::GetBoidNeighbourHood(ABoid* thisBoid)
{
	//create array to return from function
	TArray<class ABoid*> ReturnBoids;

	for (ABoid* Boid : MyBoids)
	{
		//as long as the boid isn't the current one
		if (Boid == thisBoid || !Boid) continue;

		//calculate distance between them
		float aDistance = (Boid->GetActorLocation() - thisBoid->GetActorLocation()).Size();
		//if within range add to neighbourhood array to return
		if (aDistance < NeighbourRadius)
		{
			ReturnBoids.Add(Boid);
		}


	}

	return ReturnBoids;
}

//find the closest boid
FVector ABoidManager::ClosestBoidPosition(ABoid* thisBoid)
{
	//variables
	float ClosestDistance = MaxFleeDistance;
	FVector returnVal = GetActorLocation();

	for(ABoid* Boid : MyBoids) 
	{
		//as long as its not the same, it exists and wasn't recently tagged
		if (Boid == thisBoid || !Boid || Boid == lastTagged)
		{
			continue;
		}
		//calculate distance
		float aDistance = (Boid -> GetActorLocation() - thisBoid -> GetActorLocation()).Size();
		//if distance within range
		if(aDistance < ClosestDistance)
		{
			//the closest distance becomes the distance calculated
			ClosestDistance = aDistance;
			//return closest boid location
			returnVal = Boid -> GetActorLocation();
		}

		if (thisBoid == TaggedBoid)
		{
			if (ClosestDistance < CatchRange)
			{ //tag new boid
				PreviousTaggedBoids.Add(lastTagged);
				lastTagged = TaggedBoid;
				TaggedBoid = Boid;
				TaggedBoid->waitCounter = TimeoutTime;

			}
		}
		//when infection mode is false - reset everyone's materials after they're no longer tagged
		if(InfectionMode == false)
		{
			for(ABoid* PreviousBoid : PreviousTaggedBoids)
			{
				Boid->Mesh->SetMaterial(0, BoidMaterial);
								
			}		
		}
	
	}
	
    return returnVal;
}

//function that makes the boid do certain behaviours depending on what is inputted
void ABoidManager::BoidBehaviour(FString behaviour, float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(behaviour == "flee")
	{
		for(ABoid* Boid : MyBoids) 
		{
			//speed up tagged boid
			TaggedBoid->Speed = BoidSpeed*6;
			//run behaviour
			Boid->UpdateFleeBoid(DeltaTime);
			//set tagged boid with unique material
			TaggedBoid->Mesh->SetMaterial(0, ChaserMaterial);

			//UE_LOG(LogTemp, Warning, TEXT("flee"));
		}
	}
	else if(behaviour == "flock")
	{
		for(ABoid* Boid : MyBoids)
		{
			//reset tagged boids speed
			TaggedBoid->Speed = BoidSpeed/6;
			//reset tagged boids materials
			TaggedBoid->Mesh->SetMaterial(0, BoidMaterial);
			//lastTagged->Mesh->SetMaterial(0, BoidMaterial);
			//run behaviour
			Boid->UpdateFlockBoid(DeltaTime);
			//UE_LOG(LogTemp, Warning, TEXT("flock"));
		}
	}
}

