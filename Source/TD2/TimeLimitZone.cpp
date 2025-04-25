// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeLimitZone.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "TP_ThirdPerson/TP_ThirdPersonGameMode.h"

ATimeLimitZone::ATimeLimitZone()
{

}

void ATimeLimitZone::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ATimeLimitZone::OnOverLapBegin);
	OnActorEndOverlap.AddDynamic(this, &ATimeLimitZone::OnOverLapEnd);


}

void ATimeLimitZone::OnOverLapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && zoneType == TimeLimitZoneType::End)
	{
		ATP_ThirdPersonCharacter* Character = Cast<ATP_ThirdPersonCharacter>(OtherActor);
		if (Character)
		{
			if (UWorld* World = GetWorld())
			{
				if (ATP_ThirdPersonGameMode* GameMode = Cast<ATP_ThirdPersonGameMode>(World->GetAuthGameMode()))
				{
					GameMode->EndTimer();
				}
			}
		}
	}
}

void ATimeLimitZone::OnOverLapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && zoneType == TimeLimitZoneType::Start)
	{
		ATP_ThirdPersonCharacter* Character = Cast<ATP_ThirdPersonCharacter>(OtherActor);
		if (Character)
		{
			if (UWorld* World = GetWorld())
			{
				if (ATP_ThirdPersonGameMode* GameMode = Cast<ATP_ThirdPersonGameMode>(World->GetAuthGameMode()))
				{
					GameMode->StartTimer();
				}
			}
		}
	}
}