// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto CurrentControlledTank = GetControlledTank();
	auto PlayerControlledTank = GetPlayertank();

//TODO : This is broken, I think get rid of GetControlledTank all together, not needed...should just log out PlayerControlledTank
	if (!PlayerControlledTank || !CurrentControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("cannot find player controlled Tank or AI tank not possesed"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI %s found playercontroller %s"), *(CurrentControlledTank->GetName()), *(PlayerControlledTank->GetName()));
	}

}

ATank* ATankAIController::GetPlayertank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController());

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}