// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "CameraElevator.generated.h"

UCLASS()
class MUSICMANSION_API ACameraElevator : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACameraElevator();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

private:
	void MoveIntoPlace();
	void SetTargetUp();
	void SetTargetDown();
	

	int targetFloor=0;
	int maxFloors=10;
	float startHeight;
};
