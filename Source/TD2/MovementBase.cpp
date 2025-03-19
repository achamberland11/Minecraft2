// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementBase.h"

// Sets default values for this component's properties
UMovementBase::UMovementBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMovementBase::BeginPlay()
{
	Super::BeginPlay();

	if (AActor* Owner = GetOwner())
	{
		StartPosition = Owner->GetActorLocation();
	}
	
}


// Called every frame
void UMovementBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateMovement(DeltaTime);
}

void UMovementBase::UpdateMovement(float DeltaTime)
{
	if (!GetOwner()) return;

	FVector NormalizedDirection = MovementDirection.GetSafeNormal();
	FVector Offset = NormalizedDirection * Speed * DeltaTime;

	FVector NewPosition = GetOwner()->GetActorLocation() + Offset;

	if (bCanMoveBackForth)
	{
		if (FVector::Dist(StartPosition, NewPosition) >= MovementRange)
		{
			MovementDirection = -MovementDirection;

			NewPosition = GetOwner()->GetActorLocation() + MovementDirection.GetSafeNormal() * Speed * DeltaTime;
		}
	}

	GetOwner()->SetActorLocation(NewPosition);
}