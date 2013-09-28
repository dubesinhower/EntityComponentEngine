#include "Entity.h"

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