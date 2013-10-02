#pragma once
#include <boost\ptr_container\ptr_vector.hpp>
#include "Message.h"

class MessageManager
{
public:
	MessageManager(void) {};
	~MessageManager(void) {};

	void addMessage(Message* m) {messages.push_back(m);};
	boost::ptr_vector<Message>& getAllMessages() {return messages;};
	void cleanup();

private:
	boost::ptr_vector<Message> messages;
};