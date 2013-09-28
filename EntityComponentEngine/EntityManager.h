#pragma once
#include <boost\ptr_container\ptr_map.hpp>
#include <boost\assign\ptr_map_inserter.hpp>
#include <vector>
#include <limits>
#include "SFML\graphics.hpp"
#include "Entity.h"
#include "SpriteManager.h"
#include "ComponentFactory.h"

class EntityManager
{
public:
	EntityManager(void) {};
	~EntityManager(void) {};

	boost::ptr_map<unsigned long, Entity>& getEntities() {return entities;};

	const bool addBackgroundTile(std::string spriteSheet, std::string sprite, float positionX, float positionY, float width, float height);

private:
	SpriteManager* sm;
	ComponentFactory cf;
	boost::ptr_map<unsigned long, Entity> entities;

	const bool addEntity(Entity* entity);
	void removeEntity(const unsigned long ID) {entities.erase(ID);};
	void removeAll() {entities.clear();};
	const std::vector<unsigned long> getIDPool();

	
};

