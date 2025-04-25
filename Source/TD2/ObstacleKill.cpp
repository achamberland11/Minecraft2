// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "ObstacleKill.h"
#include "Obstacle.h"

void AObstacleKill::OnCharacterHit(ATP_ThirdPersonCharacter* Character)
{
    UE_LOG(LogTemp, Warning, TEXT("Knockback applied to character!"));

    FVector KnockbackDirection = Character->GetActorLocation() - GetActorLocation();
    KnockbackDirection.Normalize();

    Character->LaunchCharacter(KnockbackDirection * KnockbackStrength, true, true);

    UCharacterMovementComponent* Movement = Character->FindComponentByClass<UCharacterMovementComponent>();
    if (Movement)
    {
        Movement->DisableMovement();
    }

    UCapsuleComponent* CapsuleComp = Character->GetCapsuleComponent();
    if (CapsuleComp)
    {
        CapsuleComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    }

    CharacterMesh = Character->FindComponentByClass<USkeletalMeshComponent>();
    if (CharacterMesh)
    {
        CharacterMesh->SetSimulatePhysics(true);
    }

    FTimerHandle TimerHandler;
    GetWorld()->GetTimerManager().SetTimer(TimerHandler, Character, &ATP_ThirdPersonCharacter::CallRestartPlayer, 5.0f, false);
}