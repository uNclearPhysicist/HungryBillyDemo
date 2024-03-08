// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CorrectBlueBox.generated.h"

UCLASS()
class HUNGRYBILLYDEMO_API ACorrectBlueBox : public AActor
{
	GENERATED_BODY()
	
public:	
	ACorrectBlueBox();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "MyObject")
	float GetDistanceToPlayer();

protected:
	virtual void BeginPlay() override;
};
