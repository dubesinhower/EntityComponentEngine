#pragma once
#include "Component.h"
#include "SFML\Graphics.hpp"

class RenderComponent : public Component
{
public:
	virtual const std::string familyID() const {return "renderComponent";};
};