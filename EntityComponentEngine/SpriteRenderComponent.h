#pragma once
//#include <boos
#include "RenderComponent.h"
#include "PositionComponent.h"

class SpriteRenderComponent : public RenderComponent
{
public:
	SpriteRenderComponent(void) : sprite(0) {};
	~SpriteRenderComponent(void) {};

	virtual const std::string componentID() const {return "spriteRenderComponent";};

	virtual void update()
	{
		Component* c = getOwner()->getComponent("positionComponent");
		PositionComponent* pc = static_cast<PositionComponent*>(c);

		if(pc)
		{
			sprite->setPosition(pc->getPositionX(), pc->getPositionY());
		}
	};

	sf::Sprite* getSprite() {return sprite;};
	void setSprite(sf::Sprite* sprite) {this->sprite = sprite;};

private:
	sf::Sprite* sprite;
};

