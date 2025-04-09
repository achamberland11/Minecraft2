// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "ItemJumpBoost.generated.h"

/**
 * 
 */
UCLASS()
class TD2_API AItemJumpBoost : public AItem
{
	GENERATED_BODY()

protected:
	virtual void OnCollected() override;	
};
