#pragma once
#include "client.h"
#include "dwelling.h"
#include <vector>
class Agency
{
public:
	Dwelling add_dwelling(std::string type, double price, bool is_profitable);
	void add_client(Client* c);
	void remove_client(std::string name);
	std::vector<Client*> get_interested_clients(Dwelling d);
	void write_to_file(std::string filename);
	std::vector<Client*> get_clients() { return clients; };
	std::vector<Dwelling> get_dwellings() { return this->dwellings; };
private:
	std::vector<Client*> clients;
	std::vector<Dwelling> dwellings;
};