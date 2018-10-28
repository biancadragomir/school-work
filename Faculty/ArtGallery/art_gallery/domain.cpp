#include "domain.h"
#include <string>
#include <sstream>
using namespace std;

Special_painting::Special_painting(std::string title_, std::string artist_, int year_, double temperature_) :
	Painting(title_, artist_, year_), temperature(temperature_)
{
}

bool Special_painting::is_special()
{
	return (temperature >= 18 && temperature <= 22);
}

std::string Special_painting::to_string()
{
	stringstream s;
	s << this->artist << " " << this->title << " " << this->year << " " << this->temperature << endl;
	return s.str();
}

Painting::Painting(std::string title_, std::string artist_, int year_) :
	title(title_), artist(artist_), year(year_)
{

}

bool Painting::is_special()
{
	return false;
}

std::string Painting::to_string()
{
	std::stringstream s;
	s << this->artist << " " << this->title<< " " << this->year << endl;

	return s.str();
}

int Painting::operator==(Painting * p)
{
	return(this->artist == p->artist && this->title == p->title && this->year == p->year);
}

