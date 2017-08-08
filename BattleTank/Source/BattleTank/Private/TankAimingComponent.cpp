// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "../Public/TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet;

}



void UTankAimingComponent::AimAt(FVector HitLocation,float LaunchSpeed)
{
	//auto OurTankName = GetOwner()->GetName();
	//auto BarrelLocation = Barrel->GetComponentLocation();
	//UE_LOG(LogTemp, Warning, TEXT("%s Aiming At %s from %s"), *OurTankName, *HitLocation.ToString(), *BarrelLocation.ToString());

	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector	StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	

	//Calculate the outLaunchVelocity
	if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, HitLocation, LaunchSpeed, false,0 ,0 ,ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		//auto TankName = GetOwner()->GetName();
		//UE_LOG(LogTemp, Warning, TEXT("%s aiming at at %s"),*TankName, *AimDirection.ToString());
		MoveBarrelTowards(AimDirection);

	}
	//else do nothing
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) 
{
	auto BarrelRotation = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto Deltarotator = AimAsRotator - BarrelRotation;

	UE_LOG(LogTemp, Warning, TEXT("aimasrotator %s"), *AimAsRotator.ToString());

	// Move the barrel the right amount this frame
	// Given a max elevation speed and the frame time
}
