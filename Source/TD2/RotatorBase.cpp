// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatorBase.h"

// Sets default values for this component's properties
URotatorBase::URotatorBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URotatorBase::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URotatorBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (AActor* Owner = GetOwner()) {
		FRotator NewRotation = Owner->GetActorRotation();

		if (bRotateX)
			NewRotation.Roll += (Speed * DeltaTime);
		if (bRotateY)
			NewRotation.Pitch += (Speed * DeltaTime);
		if (bRotateZ)
			NewRotation.Yaw += (Speed * DeltaTime);

		Owner->SetActorRotation(NewRotation);
	}
}

