#include "EntityManager.h"

const bool EntityManager::addEntity(Entity* newEntity)
{
	if(IDsAvailable)
	{
		unsigned long ID = lastIDUsed;
		unsigned long attemptsMade = 0;
		bool IDFound = false;
		while(!IDFound && attemptsMade != ULONG_MAX)
		{
			if(!entities.count(ID))
			{
				IDFound = true;
				std::unique_ptr<Entity> up(newEntity);
				entities.insert(std::pair<unsigned long, std::unique_ptr<Entity>>(ID, up));
				lastIDUsed = ID;
			}
			else if(ID == ULONG_MAX)
				ID = 0;
			else
				ID++;

			if(attemptsMade + 1 != ULONG_MAX)
				attemptsMade++;
		}
	}
	return IDsAvailable;
}

const bool EntityManager::addBackgroundTile(std::string spriteSheet, std::string sprite, float positionX, float positionY, float width, float height)
{
	Entity* backgroundTile = new Entity;
	positionX = positionX * pixelsPerUnit;
	positionY = positionY * pixelsPerUnit;
	sf::Vector2f position(positionX, positionY);
	position = position * resolutionScalar;
	SpriteRenderComponent* src = cf.getSpriteRenderComponent(spriteSheet, sprite, position, resolutionScalar);
	backgroundTile->addComponent(src);
	PositionComponent* pc = cf.getPositionComponent(positionX, positionY);
	backgroundTile->addComponent(pc);
	SizeComponent* sc = cf.getSizeComponent(width, height);
	backgroundTile->addComponent(sc);
	return addEntity(backgroundTile);
}