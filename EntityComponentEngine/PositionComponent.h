#pragma once
#include "Component.h"
#include "SFML\System.hpp"

class PositionComponent : public Component
{
public:
	PositionComponent(void) {};
	~PositionComponent(void) {};

	virtual const std::string familyID() const {return "positionComponent";};
	virtual const std::string componentID() const {return "positionComponent";};

	const float getPositionX() const {return positionX;};
	const float getPositionY() const {return positionY;};
	void setPosition(float positionX, float positionY) {this->positionX = positionX; this->positionY = positionY;};
	void setPositionX(float positionX) {this->positionX = positionX;};
	void setPositionY(float positionY) {this->positionY = positionY;};

private:
	float positionX;
	float positionY;
};