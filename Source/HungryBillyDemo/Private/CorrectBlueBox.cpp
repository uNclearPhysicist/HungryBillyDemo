// Fill out your copyright notice in the Description page of Project Settings.


#include "CorrectBlueBox.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

ACorrectBlueBox::ACorrectBlueBox()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACorrectBlueBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    GetDistanceToPlayer();
}

float ACorrectBlueBox::GetDistanceToPlayer()
{
    APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (!PlayerController)
    {
        // Handle the case where the player controller is not found
        UE_LOG(LogTemp, Warning, TEXT("Distance to correct blue box: PlayerController not found"));
        return -1.0f;
    }

    APawn* PlayerPawn = PlayerController->GetPawn();
    if (!PlayerPawn)
    {
        // Handle the case where the player pawn is not found
        UE_LOG(LogTemp, Warning, TEXT("Distance to correct blue box: PlayerPawn not found"));
        return -1.0f;
    }

    // Get player and box locations
    FVector PlayerLocation = PlayerPawn->GetActorLocation();
    FVector MyLocation = this->GetActorLocation();

    // Calculate distance
    float Distance = FVector::Dist(MyLocation, PlayerLocation);

    // Output the distance to the log
    UE_LOG(LogTemp, Warning, TEXT("Distance to correct blue box: %f"), Distance);

    return Distance;
}

void ACorrectBlueBox::BeginPlay()
{
	Super::BeginPlay();
}
