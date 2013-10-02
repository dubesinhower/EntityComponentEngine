#pragma once
#include <boost\ptr_container\ptr_vector.hpp>
#include "Screen.h"
#include "EntityManager.h"
#include "RenderSystem.h"
#include "Entity.h"
#include "SpriteManager.h"
#include "InputManager.h"

class GameScreen : public Screen
{
public:
	GameScreen(const float resolutionScalar, const float pixelsPerUnit) : Screen(resolutionScalar, pixelsPerUnit) {};
	~GameScreen(void) {};

	virtual int run(sf::RenderWindow& window);

private:
	boost::ptr_vector<Entity> entities;
};

