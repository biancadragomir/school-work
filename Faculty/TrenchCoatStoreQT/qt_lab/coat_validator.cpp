#include "coat_validator.h"

using namespace std;

Coat_exception::Coat_exception(std::vector<std::string> _errors) : errors{ _errors }
{
}

std::vector<std::string> Coat_exception::get_errors() const
{
	return this->errors;
}

void Coat_validator::validate(const Trench_coat & c)
{
	vector<string> errors;
	if (c.get_color().size() < 3)
		errors.push_back("The color name cannot be less than 3\n");
	if (c.get_size() < 0 || c.get_size() > 100)
		errors.push_back("The size cannot be like that! \n");
	if (c.get_length() < 0)
		errors.push_back("The length cannot be negative! \n");
	if (c.get_quantity() < 0)
		errors.push_back("The quantity cannot be negative! \n");
	if (c.get_price() < 0)
		errors.push_back("The price cannot be negative! \n");

	if (c.get_photograph().size() < 5)
		errors.push_back("The link cannot be this short! \n");
	int posWww = c.get_photograph().find("www");
	int posHttp = c.get_photograph().find("http");
	if (posWww != 0 && posHttp != 0)
		errors.push_back("The photo source must start with  \"www\" or \"http\"");
	if (c.get_length() < 0)
		errors.push_back("The length cannot be negative! \n");
	if (errors.size() > 0)
		throw Coat_exception(errors);
}