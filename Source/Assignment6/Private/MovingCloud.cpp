#include "MovingCloud.h"

AMovingCloud::AMovingCloud()
{
	PrimaryActorTick.bCanEverTick = true;
	
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SetRootComponent(StaticMeshComp);
}

void AMovingCloud::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

void AMovingCloud::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RunningTime += DeltaTime;
	
	float MoveOffset = FMath::Sin(RunningTime * MoveSpeed * 0.01f) * MaxRange;
	
	FVector NewLocation = StartLocation;
	NewLocation.X += MoveOffset;
	
	SetActorLocation(NewLocation);
}

