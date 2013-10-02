#include "InputManager.h"

void InputManager::initDefaults()
{

}
//button pushed or released
void InputManager::handleSFEvent(sf::Event e)
{
	if(e.type == sf::Event::MouseButtonPressed)
	{
		if(e.mouseButton.button == sf::Mouse::Left)
		{
			sendMessage(new MouseClickMessage("left", sf::Vector2i(e.mouseButton.x, e.mouseButton.y), 1));
		}
	}
}

//constant value
void InputManager::handleSFInput()
{
	
}