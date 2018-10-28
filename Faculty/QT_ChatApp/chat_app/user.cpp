#include "user.h"
#include <sstream>

UserMessage::UserMessage(const User &u, const Message &m)
{
	this->m = m;
	this->u = u;
}

std::string UserMessage::to_string()
{
	std::stringstream ss;
	ss << "["<< this->u.get_name()<<"] " << ": " << this->m.get_message();
	return ss.str();
}

std::string User::get_user_name()
{
	return user_name;
}

std::string User::get_name()
{
	return name;
}

std::string Message::get_message()
{
	return message;
}
