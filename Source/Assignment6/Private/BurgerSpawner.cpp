#include "BurgerSpawner.h"

ABurgerSpawner::ABurgerSpawner()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ABurgerSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ABurgerSpawner::SpawnBurger, SpawnInterval, true);
}

void ABurgerSpawner::SpawnBurger()
{
	if (BurgerClass)
	{
		FVector SpawnLocation = GetActorLocation();
		SpawnLocation.X += FMath::RandRange(-SpawnRange, SpawnRange);
		SpawnLocation.Y += FMath::RandRange(-SpawnRange, SpawnRange);
		FRotator SpawnRotation = FRotator::ZeroRotator;
		
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
		
		AActor* NewBurger = GetWorld()->SpawnActor<AActor>(BurgerClass,SpawnLocation, SpawnRotation, SpawnParams);

		if (NewBurger)
		{
			NewBurger->SetLifeSpan(BurgerLifeSpan);
		}
	}
}

void ABurgerSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}