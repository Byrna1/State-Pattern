#pragma once
#include <SFML/Graphics.hpp>
class Enemy;

class EnemyState
{
protected:
    Enemy& owner;
public:
    EnemyState(Enemy& owner) : owner(owner) {}
    virtual EnemyState* update(float dt, const sf::Vector2f& playerPos) = 0;
};