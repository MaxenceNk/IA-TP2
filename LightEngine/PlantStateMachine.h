#pragma once

class Plant;

class PlantStateMachine
{
public:
    enum class State
    {
        Idle,
        Shooting,
        Reloading,
        Count
    };

    static constexpr int STATE_COUNT = static_cast<int>(State::Count);

private:
    State mState = State::Idle;
    int mAmmo = 3;
    int mMaxAmmo = 3;
    float mReloadTime = 2.0f;
    float mShootCooldown = 0.5f;
    float mTimeSinceLastShot = 0.0f;
    float mReloadProgress = 0.0f;

public:
    PlantStateMachine() {}

    void Update(Plant* pPlant, float deltaTime);
    bool CanShoot() const { return mAmmo > 0 && mState == State::Idle; }
    bool IsReloading() const { return mState == State::Reloading; }
};
