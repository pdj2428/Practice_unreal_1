// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"

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
}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();
	
	PlacedLocation = GetActorLocation();
	if(bInitializeFloaterLocations)
		SetActorLocation(InitialLocation);
	
	/*FHitResult HitResult;
	FVector LocalOffset = FVector(200.0f, 0.0f, 0.0f);

	FRotator Rotation = FRotator(0.0f, 0.0f, 1.0f);

	AddActorWorldOffset(LocalOffset, false, &HitResult);
	AddActorLocalOffset(LocalOffset, false, &HitResult);
	
	AddActorWorldRotation(Rotation, false, &HitResult);
	AddActorLocalRotation(Rotation, false, &HitResult);*/
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

		/*FHitResult HitResult;
		FVector LocalOffset = FVector(1.0f, 0.0f, 0.0f);

		FRotator Rotation = FRotator(0.0f, 0.0f, 1.0f);

		AddActorWorldOffset(LocalOffset, false, &HitResult);
		AddActorLocalOffset(LocalOffset, false, &HitResult);

		AddActorWorldRotation(Rotation, false, &HitResult);
		AddActorLocalRotation(Rotation, false, &HitResult);*/
	}

}

