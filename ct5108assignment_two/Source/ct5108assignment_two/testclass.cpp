// Fill out your copyright notice in the Description page of Project Settings.


#include "testclass.h"

// Sets default values
Atestclass::Atestclass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Atestclass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Atestclass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

