#include "RenderSystem.h"

void RenderSystem::update(boost::ptr_map<unsigned long, Entity>& entities, sf::RenderWindow& window)
{
	for(boost::ptr_map<unsigned long, Entity>::value_type p : entities)
	{
		Component* c = (p->second)->getComponent("spriteRenderComponent");
		SpriteRenderComponent* src = static_cast<SpriteRenderComponent*>(c);
		sf::Sprite* sprite = src->getSprite();
		window.draw(*sprite);
	}
}