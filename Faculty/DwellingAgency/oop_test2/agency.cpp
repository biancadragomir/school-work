#include "agency.h"
#include <fstream>
#include <exception>

using namespace std;

Dwelling Agency::add_dwelling(std::string type, double price, bool is_profitable)
{
	Dwelling d{ type, price, is_profitable };
	this->dwellings.push_back(d);
	return d;
}

void Agency::add_client(Client* c)
{
	this->clients.push_back(c);
}

void Agency::remove_client(std::string name)
{
	int ok = 0;
	for (auto d : clients)
		if (d->get_name() == name)
			ok = 1;
	if (!ok)
		throw exception("there is no client with that name \n");
	for (int i = 0; i < clients.size(); i++)
		if (clients[i]->get_name() == name)
			clients.erase(clients.begin() + i);
}

std::vector<Client*> Agency::get_interested_clients(Dwelling d)
{
	return std::vector<Client*>();
}

void Agency::write_to_file(std::string filename)
{
	ofstream o(filename);
	for (auto d : this->clients)
		o << d->to_string();
}