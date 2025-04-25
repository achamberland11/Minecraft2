#include "ItemPhase.h"
#include "EngineUtils.h"
#include "HAL/Platform.h"
#include "TD2/Obstacle.h"
#include "TimerManager.h"

void AItemPhase::OnCollected() {
    ObstaclesMeshes.Empty();
    GetWorld()->GetTimerManager().ClearTimer(collisionResetTimerHandler);

    for (TActorIterator<AObstacle> It(GetWorld()); It; ++It) {
        UStaticMeshComponent* ObstacleMesh = (*It)->GetMeshComponent();
        if (ObstacleMesh) {
            ObstacleMesh->SetCollisionProfileName(TEXT("NoCollision"));

            ObstaclesMeshes.Add(ObstacleMesh);
        }
    }

    GetWorld()->GetTimerManager().SetTimer(collisionResetTimerHandler, this, &AItemPhase::ResetCollision, itemTimer, false);
}

void AItemPhase::ResetCollision()
{
    for (UStaticMeshComponent* ObstacleMesh : ObstaclesMeshes)
    {
        if (ObstacleMesh)
        {
            ObstacleMesh->SetCollisionProfileName(TEXT("BlockAllDynamic"));
        }
    }

    ObstaclesMeshes.Empty();
}