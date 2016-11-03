// Fill out your copyright notice in the Description page of Project Settings.

#include "MusicMansion.h"
#include "CameraElevator.h"


// Sets default values
ACameraElevator::ACameraElevator()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraElevator::BeginPlay()
{
	Super::BeginPlay();
	targetFloor = 0;
	startHeight = GetActorLocation().Z;
}

// Called every frame
void ACameraElevator::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	MoveIntoPlace();
}

void ACameraElevator::MoveIntoPlace() {
	//UE_LOG(LogTemp, Log, TEXT("MoveIntoPlace"));
	float lerpRate = 0.05;
	float floorSpacing = 70;
	float currentFloorHeight = startHeight + targetFloor*floorSpacing;
	FVector targetLocation = FVector(GetTransform().GetLocation().X, GetTransform().GetLocation().Y, currentFloorHeight);
	//UE_LOG(LogTemp, Log, TEXT("Old Height: %f"), targetLocation.Z);
	FVector currentLocation = FMath::Lerp(GetTransform().GetLocation(), targetLocation, lerpRate);
	SetActorLocation(currentLocation);
	//UE_LOG(LogTemp, Log, TEXT("New Height: %f"), GetTransform().GetLocation().Z);
}

// Called to bind functionality to input
void ACameraElevator::SetupPlayerInputComponent(class UInputComponent* i_InputComponent)
{
	Super::SetupPlayerInputComponent(i_InputComponent);
	//UE_LOG(LogTemp, Log, TEXT("SETUP!"));
	//i_InputComponent->BindAction("SetTargetUp", IE_Pressed, this, &ACameraElevator::SetTargetUp);
	//i_InputComponent->BindAction("SetTargetDown", IE_Pressed, this, &ACameraElevator::SetTargetDown);
}

void ACameraElevator::SetTargetUp() {	
	targetFloor++;
	if (targetFloor > maxFloors) {
		targetFloor = maxFloors;
	}
	//UE_LOG(LogTemp, Log, TEXT("UP!: %d"), targetFloor);
}
void ACameraElevator::SetTargetDown() {
	targetFloor--;
	if (targetFloor < 0) {
		targetFloor = 0;
	}
	//UE_LOG(LogTemp, Log, TEXT("DOWN!: %d"), targetFloor);
}

