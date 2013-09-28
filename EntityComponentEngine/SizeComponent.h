#pragma once
#include "Component.h"

class SizeComponent : public Component
{
public:
	virtual const std::string familyID() const {return "sizeComponent";};
	virtual const std::string componentID() const {return "sizeComponent";};

	const float getWidth() const {return width;};
	const float getHeight() const {return height;};
	void setSize(float width, float height) {this->width = width; this->height = height;};
	void setWidth(float width) {this->width = width;};
	void setHeight(float height) {this->height = height;};

private:
	float width;
	float height;
};