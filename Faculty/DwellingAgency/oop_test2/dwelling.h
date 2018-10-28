#pragma once
#include <string>
class Dwelling
{
private:
	std::string type;
	double price;
	bool is_profitable;
public:
	Dwelling() {};
	Dwelling(std::string type_, double price_, bool is_profitable_);
	double normal_bank_rate();
	double large_bank_rate();
	bool profitable();
	std::string dwell_string();

};