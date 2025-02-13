#pragma once

#include "Entity.h"

class Zombie : public Entity
{
private:
    int health;

public:
    Zombie();

    void OnUpdate() override;

    bool IsDead() const; // Ajout de la méthode
};
