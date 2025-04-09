// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemPoint.h"
#include "TP_ThirdPerson/TP_ThirdPersonGameMode.h"

void AItemPoint::OnCollected()
{
	if (UWorld* World = GetWorld())
	{
		ATP_ThirdPersonGameMode* GameMode = Cast<ATP_ThirdPersonGameMode>(World->GetAuthGameMode());
		if (GameMode)
		{
			GameMode->IncrementScore();
		}
	}
}