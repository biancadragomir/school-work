
#pragma once
#include <string>
class Painting
{
protected:
	std::string title, artist;
	int year;

public:
	Painting() {};
	Painting(std::string title_, std::string arist_, int year_);
	virtual bool is_special();
	virtual std::string to_string();
	int operator==(Painting* p);
};

class Special_painting : public Painting
{private:
	double temperature;

public:
	Special_painting() {};
	Special_painting(std::string title_, std::string artist_, int year, double temperature);
	bool is_special();
	std::string to_string();

};