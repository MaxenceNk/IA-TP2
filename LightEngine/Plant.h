#pragma once
#include "Entity.h"
#include "PlantStateMachine.h"

class Plant : public Entity
{
private:
    PlantStateMachine mStateMachine;

public:
    void Update(float deltaTime);
    void Shoot();
};
