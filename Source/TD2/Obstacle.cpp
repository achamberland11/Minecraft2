// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/MeshMerging.h"
#include "TD2/TP_ThirdPerson/TP_ThirdPersonCharacter.h"

// Sets default values
AObstacle::AObstacle()
{
    PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();

    Mesh = this->FindComponentByClass<UStaticMeshComponent>();
    RootComponent = Mesh;

    Mesh->OnComponentHit.AddDynamic(this, &AObstacle::OnHit);
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AObstacle::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (OtherActor)
    {
        UE_LOG(LogTemp, Warning, TEXT("COlLISION"));

        ATP_ThirdPersonCharacter* Character = Cast<ATP_ThirdPersonCharacter>(OtherActor);
        if (Character)
        {
            OnCharacterHit(Character);
        }
    }

}

void AObstacle::OnCharacterHit(ATP_ThirdPersonCharacter* Character)
{
    UE_LOG(LogTemp, Warning, TEXT("Knockback applied to character!"));

    FVector KnockbackDirection = Character->GetActorLocation() - GetActorLocation();
    KnockbackDirection.Normalize();

    Character->LaunchCharacter(KnockbackDirection * KnockbackStrength, true, true);
}

UStaticMeshComponent* AObstacle::GetMeshComponent()
{
	return Mesh;
}