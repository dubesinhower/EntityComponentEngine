#pragma once
#include "SpriteFactory.h"

class SpriteManager
{
public:
	SpriteManager(void);
	~SpriteManager(void);

	sf::Sprite* getSprite(std::string spriteFactoryName, std::string spriteName);

private:
	std::map<std::string, SpriteFactory> spriteFactories;

};
