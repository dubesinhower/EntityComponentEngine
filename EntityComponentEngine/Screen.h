#pragma once
#include "SFML\Graphics.hpp"

class Screen
{
public:
	virtual void init () {};
	virtual int run (sf::RenderWindow &window) = 0;
};