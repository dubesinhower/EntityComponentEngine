#include "SpriteManager.h"

SpriteManager::SpriteManager(void)
{
	spriteFactories.insert(std::pair<std::string, SpriteFactory> ("overworldDevEnv", SpriteFactory("Images/overworldDevEnv.png", "Data/overworldDevEnv.xml")));
}

SpriteManager::~SpriteManager(void)
{

}

sf::Sprite* SpriteManager::getSprite(std::string spriteFactoryName, std::string spriteName)
{
	return spriteFactories.at(spriteFactoryName).getSprite(spriteName);
}