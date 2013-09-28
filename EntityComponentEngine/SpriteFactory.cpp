#include "SpriteFactory.h"

SpriteFactory::SpriteFactory(std::string imageFileName, std::string xmlFileName)
{
	if(!texture.loadFromFile(imageFileName))
		std::cout << "could not load " << imageFileName << std::endl;

	boost::property_tree::ptree pt = getPTree(xmlFileName);
	spriteSize = pt.get<int>("environment.tileSize");
	for(boost::property_tree::ptree::value_type& v : pt.get_child("environment.tileTypes"))
		if(v.first == "type")
		{
			sf::Vector2i spritePosition(v.second.get<int>("texturePosition.x"), v.second.get<int>("texturePosition.y"));
			std::string spriteName = v.second.get<std::string>("name");
			spritePositionInTexture.insert(std::pair<std::string, sf::Vector2i> (spriteName, spritePosition));
		}
}

SpriteFactory::~SpriteFactory(void)
{

}

sf::Sprite* SpriteFactory::getSprite(std::string spriteName)
{
	sf::Vector2i spritePosition = spritePositionInTexture.at(spriteName);
	spritePosition = spritePosition * spriteSize;
	sf::IntRect spriteBox(spritePosition, sf::Vector2i(spriteSize, spriteSize));
	return new sf::Sprite(texture, spriteBox);
}