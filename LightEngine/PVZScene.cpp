#include "PVZScene.h"
#include "Plant.h"
#include "Zombie.h"
#include "Projectile.h"
#include <iostream>

void PVZScene::OnInitialize()
{
    // Initialisation des plantes
    pPlant1 = CreateEntity<Plant>(50, sf::Color::Green);
    pPlant1->SetPosition(120, 120);

    pPlant2 = CreateEntity<Plant>(50, sf::Color::Green);
    pPlant2->SetPosition(120, 360);

    pPlant3 = CreateEntity<Plant>(50, sf::Color::Green);
    pPlant3->SetPosition(120, 600);
}

void PVZScene::OnEvent(const sf::Event& event)
{
    // Gestion des événements (clavier, souris)
}

void PVZScene::OnUpdate()
{
    float deltaTime = GetDeltaTime();

    // Mise à jour des plantes
    pPlant1->Update();
    pPlant2->Update();
    pPlant3->Update();


    // Suppression des zombies morts
    zombies.erase(std::remove_if(zombies.begin(), zombies.end(),
        [](Zombie* z) { return z->IsDead(); }), zombies.end());

    // Suppression des projectiles détruits
    projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(),
        [](Projectile* p) { return p->IsDestroyed(); }), projectiles.end());

    // Mise à jour des zombies
    for (auto* zombie : zombies)
        zombie->Update(deltaTime);

    // Mise à jour des projectiles
    for (auto* projectile : projectiles)
        projectile->Update(deltaTime);

    // Spawn de zombies aléatoires
    if (rand() % 200 == 0)
    {
        int lane = rand() % 3;
        int y = (lane == 0) ? 120 : (lane == 1) ? 360 : 600;
        SpawnZombie(1000, y);
    }
}

void PVZScene::SpawnZombie(int x, int y)
{
    Zombie* pZombie = CreateEntity<Zombie>(50, sf::Color::Red);
    pZombie->SetPosition(x, y);
    zombies.push_back(pZombie);
}

void PVZScene::SpawnProjectile(int x, int y)
{
    Projectile* pProjectile = CreateEntity<Projectile>(20, sf::Color::Yellow);
    pProjectile->SetPosition(x, y);
    projectiles.push_back(pProjectile);
}
