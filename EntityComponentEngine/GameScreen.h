#pragma once
#include <boost\ptr_container\ptr_vector.hpp>
#include "Screen.h"
#include "EntityManager.h"
#include "RenderSystem.h"
#include "Entity.h"
#include "SpriteManager.h"
#include "SpriteRenderComponent.h"
#include "PositionComponent.h"
#include "SizeComponent.h"

class GameScreen : public Screen
{
public:
	GameScreen(void);
	~GameScreen(void);

	virtual int run(sf::RenderWindow& window);

private:
	sf::Event event;
	boost::ptr_vector<Entity> entities;
};

