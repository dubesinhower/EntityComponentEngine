#pragma once
#include <iostream>
#include <boost/foreach.hpp>
#include "SFML\Graphics.hpp"
#include "SpriteRenderComponent.h"

class RenderSystem
{
public:
	RenderSystem(void) {};
	~RenderSystem(void) {};

	void update(std::map<unsigned long, std::unique_ptr<Entity>>& entities, sf::RenderWindow& window);
	
};