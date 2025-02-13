#pragma once

#include "Scene.h"
#include <vector>

class Plant;
class Zombie;
class Projectile;

class PVZScene : public Scene
{
private:
    Plant* pPlant1;
    Plant* pPlant2;
    Plant* pPlant3;

    std::vector<Zombie*> zombies;
    std::vector<Projectile*> projectiles;

public:
    void OnInitialize() override;
    void OnUpdate() override;
    void OnEvent(const sf::Event& event) override; // Ajout pour éviter erreur d'instanciation

    void SpawnZombie(int x, int y);
    void SpawnProjectile(int x, int y);
};
