#include "dwelling.h"
#include <string>
#include <sstream>
using namespace std;

Dwelling::Dwelling(std::string type_, double price_, bool is_profitable_) : type(type_), price(price_), is_profitable(is_profitable_)
{
}

double Dwelling::normal_bank_rate()
{
	return price / 1000;
}

double Dwelling::large_bank_rate()
{
	return price / 100;
}

bool Dwelling::profitable()
{
	return this->is_profitable;
}

std::string Dwelling::dwell_string()
{
	stringstream s;
	s << this->type << " " << this->price << " " << this->is_profitable << endl;
	return s.str();
}