#include "GameScreen.h"

int GameScreen::run(sf::RenderWindow& window)
{
	EntityManager em(resolutionScalar, pixelsPerUnit);
	em.addBackgroundTile("overworldDevEnv", "grass", 0, 0, .5f, .5f);
	em.addBackgroundTile("overworldDevEnv", "dirt", 0, .5, .5f, .5f);
	em.addBackgroundTile("overworldDevEnv", "water", .5f, 0, .5f, .5f);
	em.addBackgroundTile("overworldDevEnv", "sand", .5f, .5f, .5f, .5f);
	MessageManager mm;
	InputManager im(mm);
	RenderSystem rs;

	bool windowHasFocus = true;

	while(true)
	{
		window.clear(sf::Color::Black);
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				return (-1);
			}
			if(event.type == sf::Event::LostFocus)
				windowHasFocus = false;
			if(event.type == sf::Event::GainedFocus)
				windowHasFocus = true;
			im.handleSFEvent(event);
		}
		
		im.handleSFInput();
		rs.update(em.getAllEntities(), window);
		window.display();
	}

	return (-1);
}