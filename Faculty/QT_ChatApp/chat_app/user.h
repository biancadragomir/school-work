#pragma once
#include <string>
class User
{
private:
	std::string user_name;
	std::string	name;
public:
	User(){}
	~User(){}
	User(const std::string &un, const std::string &n) : user_name{ un }, name{ n }{}
	std::string get_user_name();
	std::string get_name();
	bool operator==(User u) { return this->user_name == u.user_name; };
};

class Message
{
private:

	std::string message;
public:
	Message(){}
	~Message(){}
	Message(const std::string &m) : message{ m } {};
	std::string get_message();

};

class UserMessage
{
private:
	Message m;
	User u;

public:
	UserMessage(const User &u, const Message &m);
	UserMessage(){}
	~UserMessage(){}
	std::string to_string();
};