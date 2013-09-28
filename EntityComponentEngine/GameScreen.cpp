#include "GameScreen.h"

GameScreen::GameScreen(void)
{
	
}

GameScreen::~GameScreen(void)
{

}

int GameScreen::run(sf::RenderWindow& window)
{
	EntityManager em;
	SpriteManager sm;
	Entity* e = new Entity;
	sf::Sprite* sprite = sm.getSprite("overworldDevEnv", "grass");
	SpriteRenderComponent* src = new SpriteRenderComponent;
	src->setSprite(sprite);
	e->addComponent(src);
	em.addBackgroundTile("overworldDevEnv", "grass", 0, 0, 32, 32);
	RenderSystem rs;

	while(true)
	{
		window.clear(sf::Color::Black);
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				return (-1);
			}
			
			if(event.type == sf::Event::KeyPressed)
			{
				switch(event.key.code)
				{
				case sf::Keyboard::Escape:
					return (-1);
					break;
				default:
					break;
				}
			}
		}

		window.draw(*src->getSprite());

		std::cout << em.getEntities().size() << std::endl;
		rs.update(em.getEntities(), window);
		window.display();
	}

	return (-1);
}