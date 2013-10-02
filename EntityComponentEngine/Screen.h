#pragma once
#include "SFML\Graphics.hpp"

class Screen
{
public:
	Screen(const float resolutionScalar, const float pixelsPerUnit) : resolutionScalar(resolutionScalar) , pixelsPerUnit(pixelsPerUnit) {};

	virtual void init () {};
	virtual int run (sf::RenderWindow &window) = 0;

protected:
	const float resolutionScalar;
	const float pixelsPerUnit;
	sf::Event event;
};