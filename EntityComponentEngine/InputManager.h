#pragma once
#include "SFML\Graphics.hpp"
#include "MessageSender.h"
#include "MouseClickMessage.h"

class InputManager : public MessageSender
{
public:
	InputManager(MessageManager& mm) : MessageSender(mm) {initDefaults();};
	~InputManager(void) {};

	void initDefaults();

	void handleSFEvent(sf::Event e);
	void handleSFInput();
};