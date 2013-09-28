#pragma once
#include <string>
#include <iostream>
#include <map>
#include "SFML\Graphics.hpp"
#include "XMLReader.h"

class SpriteFactory : public XMLReader
{
public:
	SpriteFactory(std::string imageFileName, std::string xmlFileName);
	~SpriteFactory(void);

	sf::Sprite* getSprite(std::string spriteName);

private:
	sf::Texture texture;
	int spriteSize;
	std::map<std::string, sf::Vector2i> spritePositionInTexture;
};