// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "ItemPhase.generated.h"

/**
 * 
 */
UCLASS()
class TD2_API AItemPhase : public AItem
{
	GENERATED_BODY()


protected:
	virtual void OnCollected() override;

private:
	UPROPERTY(EditAnywhere) float itemTimer;

	TArray<UStaticMeshComponent*> ObstaclesMeshes;
	FTimerHandle collisionResetTimerHandler;

	void ResetCollision();
};
