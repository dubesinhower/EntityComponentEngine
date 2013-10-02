#pragma once
#include <string>
#include <boost/ptr_container/ptr_map.hpp>
#include "Component.h"

class Component;

class Entity
{
public:
	Entity() {};
	~Entity() {};

	const bool hasComponent(const std::string componentID);
	Component* getComponent(const std::string componentID);
	void addComponent(Component* newComponent);
	void clearComponents() {components.clear();};

private:
	boost::ptr_map<std::string, Component> components;
};