#include "repo.h"
#include <fstream>
#include <iostream>
using namespace std;

void Repository::add_painting(Painting * p)
{
	paintings.push_back(p);
}

void Repository::remove_painting(Painting * p)
{
	for (int i = 0; i < paintings.size(); i++)
		if (paintings[i]->to_string() == p->to_string())
			paintings.erase(paintings.begin() + i);
}

std::vector<Painting*> Repository::get_all()
{
	return paintings;
}

void Repository::write_to_file(std::string filename)
{
	ofstream o(filename);
	if (!o)
		throw exception("the file couldn't be opened! \n");
	for (auto d : paintings)
		o << d->to_string();
}

bool Repository::exists(Painting * p)
{
	for (auto p1 : paintings)
		if (p1 == (p))
			return true;
	return false;
}
