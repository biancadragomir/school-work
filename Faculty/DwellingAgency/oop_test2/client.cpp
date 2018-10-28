#include "client.h"
#include <string>
#include <sstream>
using namespace std;
Client::Client(std::string name_, double salary_) : name(name_), salary(salary_)
{
}
double Client::total_income()
{
	return salary;
}

std::string Client::to_string()
{
	stringstream s;
	s << "name: " << this->name << ", salary: " << salary << ", income: " << total_income() << endl;
	return s.str();
}

Wealthy_client::Wealthy_client(std::string name_, double salary_, double inv_money_) : Client(name_, salary_), money_from_investments(inv_money_)
{
}

double Wealthy_client::total_income()
{
	return salary + money_from_investments;
}

std::string Wealthy_client::to_string()
{
	std::stringstream s;
	s << "name: " << this->name << ", salary: " << salary << ", inv. money: " << money_from_investments << ", income: " << this->total_income() << endl;
	return s.str();
}

bool Wealthy_client::is_interested(Dwelling d)
{
	if (this->total_income() >= d.large_bank_rate() && d.profitable())return true;
	return false;
}

Normal_client::Normal_client(std::string name_, double salary_) : Client(name_, salary_)
{
}

bool Normal_client::is_interested(Dwelling d)
{
	if (this->total_income() >= d.normal_bank_rate())return true;
	return false;
}