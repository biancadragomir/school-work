#pragma once
#include <vector>
#include "user.h"
#include "subject.h"
class ChatSession: public Subject
{
public:
	//ChatSession() {};
	//~ChatSession() {};

	void add_message(User& u, Message& m)
	{
		UserMessage um{ u, m };
		messages.push_back(um);
		this->notify();
	}
	std::vector<UserMessage> messages;
	std::vector<UserMessage> get_messages();

};