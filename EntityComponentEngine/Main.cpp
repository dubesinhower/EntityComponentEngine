#pragma once
#include <vector>
#include "SFML\Graphics.hpp"
#include "Screens.h"

int main()
{
	std::vector<Screen*> screens;
	int currentScreen = 0;

	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "EntityComponentEngine");

	screens.push_back(new GameScreen);

	while (currentScreen >= 0)
	{
		currentScreen = screens[currentScreen]->run(window);
	}

	return 0;
}