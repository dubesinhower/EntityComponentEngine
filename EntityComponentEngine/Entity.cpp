#include "Entity.h"

const bool Entity::hasComponent(const std::string componentID)
{
	return (bool)components.count(componentID);
}

Component* Entity::getComponent(const std::string componentID)
{
	boost::ptr_map<std::string, Component>::iterator i = components.find(componentID);
	return i->second;
}

void Entity::addComponent(Component* component)
{
	component->setOwner(this);
	std::string key = component->componentID();
	components.insert(key, component);
}