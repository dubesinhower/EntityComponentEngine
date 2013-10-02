#pragma once
#include <string>
#include "InputMessage.h"
#include "SFML\System.hpp"

class MouseClickMessage : public InputMessage
{
public:
	MouseClickMessage(const std::string button, const sf::Vector2i position, int timeToLive) : button(button), position(position) {this->timeToLive = timeToLive;};
	virtual ~MouseClickMessage(void) {};
	MouseClickMessage* clone() const{return new MouseClickMessage(*this);};

	virtual const std::string messageID() const {return "mouseClickMessage";};

	const std::string button;
	const sf::Vector2i position;
	int timeToLive;
};