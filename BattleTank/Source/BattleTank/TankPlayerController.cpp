// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetControlledTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("No Possesed Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Poseesing : %s"),*(PlayerTank->GetName()));
	}

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());


}
