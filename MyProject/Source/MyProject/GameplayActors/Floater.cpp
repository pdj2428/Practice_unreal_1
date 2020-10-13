// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
AFloater::AFloater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh"));

	InitialLocation = FVector(0.0f);
	PlacedLocation = FVector(0.0f);
	WorldOrigin = FVector(0.0f, 0.0f, 0.0f);

	InitialDirection = FVector(0.0f, 0.0f, 0.0f);

	bInitializeFloaterLocations = false;
	bShouldFloat = false;

	InitialForce = FVector(20000.0f, 0.0f, 0.0f);
	InitialTorque = FVector(20000.0f, 0.0f, 0.0f);
}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();
	
	float initialX = FMath::FRandRange(-500.f, 500.f);
	float initialY = FMath::FRandRange(-500.f, 500.f);
	float initialZ = FMath::FRandRange(-500.f, 500.f);

	InitialLocation.X = initialX;
	InitialLocation.Y = initialY;
	InitialLocation.Z = initialZ;

	PlacedLocation = GetActorLocation();
	if(bInitializeFloaterLocations)
		SetActorLocation(InitialLocation);
	
	
}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bShouldFloat)
	{
		FHitResult HitResult;
		AddActorLocalOffset(InitialDirection, false, &HitResult);

		FVector HitLocation = HitResult.Location;
	}

}

