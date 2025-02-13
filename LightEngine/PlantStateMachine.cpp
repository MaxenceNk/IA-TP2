#include "PlantStateMachine.h"
#include "Plant.h"

void PlantStateMachine::Update(Plant* pPlant, float deltaTime)
{
    if (mState == State::Shooting)
    {
        mTimeSinceLastShot += deltaTime;
        if (mTimeSinceLastShot >= mShootCooldown)
        {
            mAmmo--;
            mTimeSinceLastShot = 0.0f;

            if (mAmmo > 0)
                mState = State::Idle;
            else
                mState = State::Reloading;
        }
    }
    else if (mState == State::Reloading)
    {
        mReloadProgress += deltaTime;
        if (mReloadProgress >= mReloadTime)
        {
            mAmmo = mMaxAmmo;
            mReloadProgress = 0.0f;
            mState = State::Idle;
        }
    }
}
