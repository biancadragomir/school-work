#include "trench_coat.h"
#include <assert.h>
#include <Windows.h>
#include <shellapi.h>
#include <string>
#include <vector>
#include "utils.h"

using namespace std;

int Trench_coat::set_size(int new_size)
{
	this->size = new_size; return 1;
}

Trench_coat::Trench_coat() : size(0), color(""), price(0), quantity(0), photograph(""), length(0) { }// the default constructor

																									 //base entity
Trench_coat::Trench_coat(int size, const std::string& color, int price, int quantity, const std::string& photograph, int length)
{
	this->size = size;
	this->color = color;
	this->price = price;
	this->quantity = quantity;
	this->photograph = photograph;
	this->length = length;
}

//lab activity
int Trench_coat::operator==(const Trench_coat& t1)
{
	int ok = 0;
	if (this->get_size() == t1.get_size() && this->get_photograph() == t1.get_photograph())
		ok = 1;
	return ok;

}
int Trench_coat::operator<(int nr)
{
	if (this->get_length() < nr)
		return 1;
	return 0;
}


int Trench_coat::open_photo()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->get_photograph().c_str(), NULL, SW_SHOWMAXIMIZED); return 1;
}

std::istream & operator >> (std::istream & is, Trench_coat & t)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 6)
		return is;

	t.size = stod(tokens[0]);
	t.color = tokens[1];
	t.price = stod(tokens[2]);
	t.quantity = stod(tokens[3]);
	t.photograph = tokens[4];
	t.length = stod(tokens[5]);

	return is;
}

std::ostream & operator<<(std::ostream & os, const Trench_coat & t)
{
	os << t.get_size() << "," << t.get_color() << "," << t.get_price() << "," << t.get_quantity() << "," << t.get_photograph() << "," << t.get_length() << "\n";
	return os;
}