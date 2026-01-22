// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingCloud.generated.h"

UCLASS()
class ASSIGNMENT6_API AMovingCloud : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingCloud();
	
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* StaticMeshComp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cloud Settings")
	float MoveSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cloud Settings")
	float MaxRange = 200.0f;
	
protected:
	virtual void BeginPlay() override;

private:
	FVector StartLocation;
	float RunningTime = 0.0f;

};
