#pragma once
#include <string>
#include "dwelling.h"
class Client
{
protected:
	std::string name;
	double salary;

public:
	Client() {};
	Client(std::string name_, double salary_);
	std::string get_name() { return this->name; };
	virtual double total_income();
	virtual std::string to_string();
	virtual bool is_interested(Dwelling d)=0;
};

class Normal_client : public Client
{
public:
	Normal_client() {};
	Normal_client(std::string name_, double salary_);

	bool is_interested(Dwelling d);
};

class Wealthy_client : public Client
{
private:
	double money_from_investments;

public:
	Wealthy_client() {};
	Wealthy_client(std::string name_, double salary_, double inv_money_);
	double total_income();
	std::string to_string();
	bool is_interested(Dwelling d);
};