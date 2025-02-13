#include "Plant.h"
#include "Projectile.h"
#include "PVZScene.h"

void Plant::Update(float deltaTime)
{
    mStateMachine.Update(this, deltaTime);
}

void Plant::Shoot()
{
    if (!mStateMachine.CanShoot())
        return;

    Projectile* pProjectile = CreateEntity<Projectile>(5, sf::Color::Yellow);
    pProjectile->SetPosition(GetPosition().x + 65, GetPosition().y);
    pProjectile->SetRigidBody(true);
    pProjectile->GoToDirection(1000, GetPosition().y, 100.f);
}
