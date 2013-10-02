#pragma once
#include <vector>
#include "SFML\Graphics.hpp"
#include "Screens.h"
#include <iostream>

int main()
{
	std::vector<Screen*> screens;
	int currentScreen = 0;

	//change the resolution
	sf::RenderWindow window(sf::VideoMode(1680, 1024, 32), "EntityComponentEngine", sf::Style::Close);
	//change me!
	float pixelsPerUnit = 64.0f;
	float unitsPerScreenWidth = float(window.getSize().x / pixelsPerUnit);
	int recommendedUnitsPerScreenWidth = 20;
	float resolutionScalar = unitsPerScreenWidth / recommendedUnitsPerScreenWidth;
	//~~~~~~~~~~

	std::cout << resolutionScalar << std::endl;

	screens.push_back(new GameScreen(resolutionScalar, pixelsPerUnit));

	while (currentScreen >= 0)
	{
		currentScreen = screens[currentScreen]->run(window);
	}

	for(Screen* s : screens)
	{
		delete(s);
	}

	return 0;
}