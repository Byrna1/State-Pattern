#pragma once

#include "EnemyState.h"

class PatrolState : public EnemyState
{
    int nextWaypoint;
    int direction;
public:
    PatrolState(Enemy& owner);
    EnemyState* update(float dt, const sf::Vector2f& playerPos) override;
};

class IdleState : public EnemyState
{
    float idleTimer;
public:
    IdleState(Enemy& owner);
    EnemyState* update(float dt, const sf::Vector2f& playerPos) override;
};

class ChaseState : public EnemyState
{
public:
    ChaseState(Enemy& owner);
    EnemyState* update(float dt, const sf::Vector2f& playerPos) override;
};

class ReturnState : public EnemyState
{
public:
    ReturnState(Enemy& owner);
    EnemyState* update(float dt, const sf::Vector2f& playerPos) override;
};