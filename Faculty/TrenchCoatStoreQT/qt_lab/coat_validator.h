#pragma once

#include <string>
#include <vector>
#include "trench_coat.h"

class Coat_exception
{
private:
	std::vector<std::string> errors;
public:
	Coat_exception(std::vector<std::string> _errors);
	std::vector<std::string> get_errors() const;
};

class Coat_validator
{
public:
	Coat_validator() {}
	static void validate(const Trench_coat& c);
};