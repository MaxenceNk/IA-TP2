#include "PVZScene.h"

#include "Plant.h"
#include "Zombie.h"
#include "Projectile.h"

#include "Debug.h"

void PVZScene::OnInitialize()
{
	pPlant1 = SpawnPlant(120, 120);
	pPlant2 = SpawnPlant(120, 360);
	pPlant3 = SpawnPlant(120, 600);

	pPlantSelected = nullptr;
}

void PVZScene::OnEvent(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		ShootProjectile(pPlant1);
		ShootProjectile(pPlant2);
		ShootProjectile(pPlant3);
	}

	if (event.mouseButton.button == sf::Mouse::Button::Right)
	{
		SpawnZombie(event.mouseButton.y);
	}
	
}

void PVZScene::TrySetSelectedEntity(Plant* pEntity, int x, int y)
{
	if (pEntity->IsInside(x, y) == false)
		return;
	pPlantSelected = pEntity;
}

void PVZScene::OnUpdate()
{
	if (pPlantSelected != nullptr)
	{
		sf::Vector2f position = pPlantSelected->GetPosition();
		Debug::DrawCircle(position.x, position.y, 10, sf::Color::Blue);
	}
}

Plant* PVZScene::SpawnPlant(int x, int y)
{
	Plant* pPlant;
	
	pPlant = CreateEntity<Plant>(50, sf::Color::Green);
	pPlant->SetPosition(x, y);
	pPlant->SetRigidBody(true);

	return pPlant;
}

void PVZScene::TrySetSelectedPlant(sf::Event event)
{
	TrySetSelectedEntity(pPlant1, event.mouseButton.x, event.mouseButton.y);
	TrySetSelectedEntity(pPlant2, event.mouseButton.x, event.mouseButton.y);
	TrySetSelectedEntity(pPlant3, event.mouseButton.x, event.mouseButton.y);
}

void PVZScene::ShootProjectile(Plant* pPlant)
{
	Projectile* pProjectile = CreateEntity<Projectile>(5, sf::Color::Yellow);
	pProjectile->SetPosition(pPlant->GetPosition().x + 65, pPlant->GetPosition().y);
	pProjectile->SetRigidBody(true);
	pProjectile->GoToDirection(1000, pPlant->GetPosition().y, 100.f);
}

void PVZScene::SpawnZombie(int pMousePosition)
{
	int zombieSpot = 0;
	Zombie* pZombie = CreateEntity<Zombie>(50, sf::Color::Red);

	if (pMousePosition < 240.f) {
		zombieSpot = 120;
	}
	else if (240.f <= pMousePosition && pMousePosition < 480.f) {
		zombieSpot = 360;
	}
	else {
		zombieSpot = 600;
	}

	pZombie->SetPosition(1280, zombieSpot);
	pZombie->SetRigidBody(true);
	pZombie->GoToDirection(0, zombieSpot, 50.f);
}
