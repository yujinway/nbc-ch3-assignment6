#include "OrbitFish.h"
#include "SkeletonTreeBuilder.h"

AOrbitFish::AOrbitFish()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	SetRootComponent(SceneComp);
	
	SkeletalMeshComp->SetupAttachment(SceneComp);
	SkeletalMeshComp->SetRelativeLocation(FVector(OrbitalRadius, 0.0f, 0.0f));
}

void AOrbitFish::BeginPlay()
{
	Super::BeginPlay();
}

void AOrbitFish::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
}

