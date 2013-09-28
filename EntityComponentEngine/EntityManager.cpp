#include "EntityManager.h"

const bool EntityManager::addEntity(Entity* entity)
{
	bool IDsAvailable = true;
	std::vector<unsigned long> IDsInUse = getIDPool();
	unsigned long ID = 0;
	bool IDGood = false;
	bool IDInPool = false;
	while(!IDGood && IDsAvailable)
	{
		for(unsigned long l : IDsInUse)
		{
			if(ID == l && ID != ULONG_MAX)
			{
				IDInPool = true;
				ID++;
			}
		}
		if(!IDInPool)
			IDGood = true;
		if(ID == ULONG_MAX)
			IDsAvailable = false;
	}
	if(IDsAvailable)
	{
		boost::assign::ptr_map_insert<Entity> (entities) (ID);
	}
	return IDsAvailable;
}

const std::vector<unsigned long> EntityManager::getIDPool()
{
	std::vector<unsigned long> currentlyUsedIDs;
	for(boost::ptr_map<unsigned long, Entity>::iterator i = entities.begin(), e = entities.end(); i != e; ++i)
	{
		currentlyUsedIDs.push_back(i->first);
	}
	return currentlyUsedIDs;
}

const bool EntityManager::addBackgroundTile(std::string spriteSheet, std::string sprite, float positionX, float positionY, float width, float height)
{
	Entity* backgroundTile = new Entity;
	sf::Vector2f position(positionX, positionY);\
	SpriteRenderComponent* src = cf.getSpriteRenderComponent(spriteSheet, sprite, position);
	backgroundTile->addComponent(src);
	PositionComponent* pc = cf.getPositionComponent(positionX, positionY);
	backgroundTile->addComponent(pc);
	SizeComponent* sc = cf.getSizeComponent(width, height);
	backgroundTile->addComponent(sc);
	return addEntity(backgroundTile);
}