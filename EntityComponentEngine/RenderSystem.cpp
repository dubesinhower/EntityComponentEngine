#include "RenderSystem.h"

void RenderSystem::update(std::map<unsigned long, std::unique_ptr<Entity>>& entities, sf::RenderWindow& window)
{
	for(std::map<unsigned long, std::unique_ptr<Entity>>::value_type v : entities)
	{
		Component* c = (v.second)->getComponent("spriteRenderComponent");
		SpriteRenderComponent* src = static_cast<SpriteRenderComponent*>(c);
		sf::Sprite* sprite = src->getSprite();
		window.draw(*sprite);
	}
}