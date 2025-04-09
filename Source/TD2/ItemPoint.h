// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "ItemPoint.generated.h"

/**
 * 
 */
UCLASS()
class TD2_API AItemPoint : public AItem
{
	GENERATED_BODY()
	
protected:
	virtual void OnCollected() override;
};
