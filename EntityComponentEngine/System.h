#pragma once
#include <boost\ptr_container\ptr_map.hpp>
#include "Entity.h"

class System
{
public:
	virtual void update(boost::ptr_map<unsigned long, Entity>& entities) const = 0;
};