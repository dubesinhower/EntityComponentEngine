#pragma once
#include <string>
#include "Entity.h"

class Entity;

class Component
{
public:
	Component(void) : ownerEntity(0) {};
	virtual ~Component() = 0 {};

	virtual const std::string componentID() const = 0;
	virtual const std::string familyID() const = 0;

	virtual void update() {};

	void setOwner(Entity* entity) {ownerEntity = entity;};
	Entity* getOwner() const {return ownerEntity;};

private:
	Entity* ownerEntity;
};