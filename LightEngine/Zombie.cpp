#include "Zombie.h"

Zombie::Zombie()
{
    health = 100; // Sant� initiale du zombie
}

void Zombie::OnUpdate()
{
    // Ajoute ici le comportement du zombie (ex: se d�placer vers les plantes)
	GoToDirection(0, 0, 100.f); // D�placement vers la gauche
    if (health <= 0)
        Destroy(); // Marquer le zombie pour suppression
}

bool Zombie::IsDead() const
{
    return health <= 0;
}
