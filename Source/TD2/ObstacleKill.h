// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstacle.h"
#include "ObstacleKill.generated.h"

/**
 * 
 */
UCLASS()
class TD2_API AObstacleKill : public AObstacle
{
	GENERATED_BODY()

protected:
	virtual void OnCharacterHit(ATP_ThirdPersonCharacter* Character) override;

private:
	USkeletalMeshComponent* CharacterMesh;
};