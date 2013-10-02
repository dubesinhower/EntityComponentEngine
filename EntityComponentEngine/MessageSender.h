#pragma once
#include "Message.h"
#include "MessageManager.h"

class MessageSender
{
public:
	MessageSender(MessageManager& mm) : mm(mm) {};
	~MessageSender(void) {};

	void changeMessageManager(MessageManager& mm) {this->mm = mm;};

	void sendMessage(Message* newMessage) {mm.addMessage(newMessage);};

protected:
	MessageManager& mm;
};