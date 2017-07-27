// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"
#include "../Public/TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto CurrentControlledTank = GetControlledTank();
	auto PlayerControlledTank = GetPlayertank();


	if (!PlayerControlledTank  || !CurrentControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("cannot find player controlled Tank or AI tank not possesed"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI %s found playercontroller %s"),*(CurrentControlledTank->GetName()), *(PlayerControlledTank->GetName()));
	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayertank())
	{
		// TODO move towards player

		// Aim towards player
		AimTowardPlayer();
	
		// Fire if Ready

	}
}


ATank* ATankAIController::GetPlayertank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

}

void ATankAIController::AimTowardPlayer()
{
	GetControlledTank()->AimAt(GetPlayertank()->GetActorLocation());
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

} 
