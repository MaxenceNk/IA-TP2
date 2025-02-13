#pragma once

#include "Entity.h"

class Projectile : public Entity
{
private:
    bool destroyed;

public:
    Projectile();

    void OnUpdate() override;

    bool IsDestroyed() const; // Ajout de la méthode
};
