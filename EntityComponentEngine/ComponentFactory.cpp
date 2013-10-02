#include "ComponentFactory.h"

PositionComponent* ComponentFactory::getPositionComponent(float positionX, float positionY)
{
	PositionComponent* pc = new PositionComponent;
	pc->setPosition(positionX, positionY);
	return pc;
}

SizeComponent* ComponentFactory::getSizeComponent(float width, float height)
{
	SizeComponent* sc = new SizeComponent;
	sc->setSize(width, height);
	return sc;
}

SpriteRenderComponent* ComponentFactory::getSpriteRenderComponent(std::string spriteSheet, std::string sprite, sf::Vector2f initialPosition, float scale)
{
	SpriteRenderComponent* src = new SpriteRenderComponent;
	sf::Sprite* s = sm.getSprite(spriteSheet, sprite);
	s->setPosition(initialPosition);
	s->setScale(scale, scale);
	src->setSprite(s);
	return src;
}
