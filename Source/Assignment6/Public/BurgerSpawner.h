#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BurgerSpawner.generated.h"

UCLASS()
class ASSIGNMENT6_API ABurgerSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ABurgerSpawner();

protected:
	virtual void BeginPlay() override;

	void SpawnBurger();
public:	
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	TSubclassOf<AActor> BurgerClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner Settings")
	float SpawnInterval = 3.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner Settings")
	float SpawnRange = 100.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner Settings")
	float BurgerLifeSpan = 3.0f;
	
	FTimerHandle SpawnTimerHandle;
};
