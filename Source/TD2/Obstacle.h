// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "Obstacle.generated.h"

UCLASS(Abstract)
class TD2_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacle();

	UPROPERTY(VisibleAnywhere, Category = "Settings") UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere) float KnockbackStrength;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION() void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	virtual void OnCharacterHit(ATP_ThirdPersonCharacter* Character);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UStaticMeshComponent* GetMeshComponent();

};
