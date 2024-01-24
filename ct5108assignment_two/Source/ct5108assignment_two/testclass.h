// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "testclass.generated.h"

UCLASS()
class CT5108ASSIGNMENT_TWO_API Atestclass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Atestclass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
