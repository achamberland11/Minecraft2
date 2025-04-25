// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "TP_ThirdPerson/TP_ThirdPersonGameMode.h"

// Sets default values
AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = false;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	Mesh->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnOverLapBegin);
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItem::OnOverLapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		ATP_ThirdPersonCharacter* Character = Cast<ATP_ThirdPersonCharacter>(OtherActor);
		if (Character)
		{
			OnCollected();

			SetActorHiddenInGame(true);
			SetActorEnableCollision(false);
		}
	}
}

void AItem::RespawnItem()
{
	UE_LOG(LogTemp, Log, TEXT("Respawn item"));

	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
}

