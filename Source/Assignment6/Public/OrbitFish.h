#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OrbitFish.generated.h"

UCLASS()
class ASSIGNMENT6_API AOrbitFish : public AActor
{
	GENERATED_BODY()
	
public:	
	AOrbitFish();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USkeletalMeshComponent* SkeletalMeshComp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneComp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fish Settings")
	float RotationSpeed = 80.0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fish Settings")
	float OrbitalRadius = 100.0f;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
