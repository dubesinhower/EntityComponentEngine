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

	void update(boost::ptr_map<unsigned long, Entity>& entities, sf::RenderWindow& window);
	
};