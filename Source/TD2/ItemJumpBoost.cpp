// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemJumpBoost.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"

void AItemJumpBoost::OnCollected()
{
	APlayerController* PlayerCharacter = GetWorld()->GetFirstPlayerController();
	if (PlayerCharacter)
	{
		ATP_ThirdPersonCharacter* Character = Cast<ATP_ThirdPersonCharacter>(PlayerCharacter->GetPawn());
		if (Character)
		{
			Character->ActivateBoostJump();
		}
	}
}