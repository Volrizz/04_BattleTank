// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not finded a player tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController aiming at: %s"), *PlayerTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetPlayerTank();
	FVector PlayerLocation = PlayerTank->GetActorLocation(); //out parameter
	if (!GetControlledTank()) { return; }
	if (GetPlayerTank())
	{
		GetControlledTank()->AimAt(PlayerLocation);
	}

	//TODO move towards the player

	//TODO fire if ready
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}