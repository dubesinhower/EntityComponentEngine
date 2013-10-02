#pragma once
#include <string>
#include <boost\noncopyable.hpp>

class Message : boost::noncopyable
{
public:
	Message(void) {};
	virtual ~Message() {};

	virtual const std::string messageID() const = 0;
	virtual const std::string familyID() const = 0;
	int timeToLive;
};