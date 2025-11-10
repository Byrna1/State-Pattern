#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "EnemyAIStates.h"

using namespace std;

class Enemy
{
	vector<sf::Vector2f> patrol;
	float visibilityRadius;
	float speed;
	float idleTime;
	sf::Sprite spr;
	sf::Vector2f position;
	sf::Sprite initAssets()
	{
		// texture from https://stealthix.itch.io/animated-slimes
		TextureManager::instance().addTexture("assets/Slime_Medium_Green.png", sf::IntRect({ 0, 0 }, { 32, 32 }), "slime0");
		TextureManager::instance().setTextureFiltering("assets/Slime_Medium_Green.png", false);
		sf::Sprite spr(TextureManager::instance().getSprite("slime0"));
		spr.setOrigin(sf::Vector2f(16, 16));
		spr.setScale(sf::Vector2f(2, 2));
		return spr;
	}
	EnemyState* state;

public:
	Enemy(const vector<sf::Vector2f> patrol, float visibilityRadius, float speed, float idleTime) : 
		spr(initAssets()), patrol(patrol), visibilityRadius(visibilityRadius), speed(speed), idleTime(idleTime)
	{
		state = new IdleState(*this);
	}
	void update(float dt, const sf::Vector2f& playerPos)
	{
		// update the state
		EnemyState* newState = state->update(dt, playerPos);
		if (newState != nullptr)
		{
			delete state;
			state = newState;
		}
	}
	void draw(sf::RenderWindow& window)
	{
		spr.setPosition(position);
		window.draw(spr);
	}
	const vector<sf::Vector2f>& getPatrol() const { return patrol; }
	const sf::Vector2f& getPosition() const { return position; }
	float getSpeed() const { return speed; }
	float getVisibilityRadius() const { return visibilityRadius; }
	float getIdleTime() const { return idleTime; }
	void setPosition(const sf::Vector2f& pos) { position = pos; }
};