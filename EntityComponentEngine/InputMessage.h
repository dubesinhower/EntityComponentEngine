#pragma once
#include <string>
#include "Message.h"

class InputMessage : public Message
{
public:
	virtual const std::string messageID() const {return "inputMessage";};
	virtual const std::string familyID() const {return "inputMessage";};
};

