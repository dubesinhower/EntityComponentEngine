#pragma once
#include "Component.h"
#include "SpriteManager.h"
#include "PositionComponent.h"
#include "SizeComponent.h"
#include "SpriteRenderComponent.h"

class ComponentFactory
{
public:
	ComponentFactory(void) {};
	~ComponentFactory(void) {};

	PositionComponent* getPositionComponent(float positionX, float positionY);
	SizeComponent* getSizeComponent(float width, float height);
	SpriteRenderComponent* getSpriteRenderComponent(std::string spriteSheet, std::string sprite, sf::Vector2f initialPosition, float scale);

private:
	SpriteManager sm;
};

