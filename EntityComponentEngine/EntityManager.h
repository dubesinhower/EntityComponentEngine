#pragma once
#include <map>
#include <limits>
#include "SFML\graphics.hpp"
#include "Entity.h"
#include "SpriteManager.h"
#include "ComponentFactory.h"

class EntityManager
{
public:
	EntityManager(const float resolutionScalar, const float pixelsPerUnit) : resolutionScalar(resolutionScalar), pixelsPerUnit(pixelsPerUnit) {IDsAvailable = true; lastIDUsed = 0;};
	~EntityManager(void) {};

	std::map<unsigned long, std::unique_ptr<Entity>>& getAllEntities() {return entities;};

	const bool addBackgroundTile(std::string spriteSheet, std::string sprite, float positionX, float positionY, float width, float height);	

private:
	const float resolutionScalar;
	const float pixelsPerUnit;
	bool IDsAvailable;
	unsigned long lastIDUsed;
	ComponentFactory cf;
	std::map<unsigned long, std::unique_ptr<Entity>> entities;
	
	void removeEntity(const unsigned long ID) {entities.erase(ID);};
	void removeAll() {entities.clear();};

	const bool addEntity(Entity* entity);
	
};

