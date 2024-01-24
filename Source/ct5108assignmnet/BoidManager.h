
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

	//editable in settings if needed
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

	//editable in UI
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		float TimeoutTime = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		float NeighbourRadius = 900;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		float SeperationWeight = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		float CohesionWeight = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		float AlignmentWeight = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		FString CurrentBehaviour = "flock";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		float BoidSpeed = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		bool InfectionMode = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		float CurvatureStrength = 1.0f;  // how strongly they do circles

	//materials to apply
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
		class UMaterial* BoidMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
		class UMaterial* ChaserMaterial;


	//necessary boid things
	USceneComponent* transform;
	TArray<class ABoid*> MyBoids;

	//needed for seek n flee
	class ABoid* lastTagged;
	class ABoid* TaggedBoid;
	TArray<class ABoid*> PreviousTaggedBoids; //for infection mode - to turn all back after disabling

	//stuff for making the debug cube to show how far the bees are supposed to go
	FVector CubeCenter = FVector(3000.0f, 3000.0f, 3000.0f);
    FVector CubeExtent = FVector(2500.0f, 2500.0f, 2500.0f);
    FColor CubeColor = FColor(255, 255, 0);


protected:
	// Called when the game starts or when spawned
	//spawn boids
	virtual void BeginPlay() override;

public:
	// Called every frame
	//update boids
	virtual void Tick(float DeltaTime) override;
	TArray<class ABoid*> GetBoidNeighbourHood(ABoid* thisBoid);

	FVector ClosestBoidPosition(ABoid* thisBoid);

	//function to switch behaviours
	UFUNCTION(BlueprintCallable, Category="Settings")
		void BoidBehaviour(FString behaviour, float DeltaTime);
	
	
};
