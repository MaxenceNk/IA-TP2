#pragma once

#include "Scene.h"

class Plant;
class Zombie;
class Projectile;

class PVZScene : public Scene
{
	Plant* pPlant1;
	Plant* pPlant2;
	Plant* pPlant3;

	Plant* pPlantSelected;

private:
	void TrySetSelectedEntity(Plant* pEntity, int x, int y);

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;

	Plant* SpawnPlant(int x, int y);
	void TrySetSelectedPlant(sf::Event);
	void ShootProjectile(Plant* pPlant);



	void SpawnZombie(int pMousePosition);
};

