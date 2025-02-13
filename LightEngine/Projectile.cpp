#include "Projectile.h"

Projectile::Projectile()
{
    destroyed = false;
}

void Projectile::OnUpdate()
{
	GoToDirection(1000, GetPosition().y, 100.f);
	if (GetPosition().x > 800)
        Destroy();
}

bool Projectile::IsDestroyed() const
{
    return destroyed;
}
