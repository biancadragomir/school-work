#include "controller.h"
#include <iostream>
#include <fstream>
using namespace std;
Controller::Controller(Repository repo_all_, Repository special_storage_): repo_all(repo_all_), 
special_storage(special_storage_)
{

}

void Controller::c_add(std::string artist_, std::string title_, int year_, bool is_special_)
{
	Painting* p;
	if (!is_special_)
	{
		p = new Painting(artist_, title_, year_);
		this->repo_all.add_painting(p);
	}
	else
	{
		double temperature_;
		cout << "temperature: ";
		cin >> temperature_; if (temperature_ < 18 || temperature_ >22)
			throw exception("introduce a temperature between 18 and 22\n");
		p = new Special_painting(artist_, title_, year_, temperature_);
		this->special_storage.add_painting(p);
	}
}

void Controller::c_remove_painting(std::string artist_, std::string title_, int year_)
{
	Painting* p = NULL;
	p = new Painting(artist_, title_, year_);

	if (this->repo_all.exists(p))
	{
		this->repo_all.remove_painting(p);

	}
	else
		if (this->special_storage.exists(p))
	{
			//p = new Special_painting(title_, artist_, year_, 0);
			this->special_storage.remove_painting(p);
	}
		else
			throw exception("the painting does not exist! \n");
	return;
}

std::vector<Painting*> Controller::c_get_all()
{
	return this->repo_all.get_all();
}

std::vector<Painting*> Controller::c_get_special_storage()
{
	return this->special_storage.get_all();
}

void Controller::c_write_to_file(std::string filename)
{
	ofstream o(filename);
	if (!o)
		throw exception("file incorrect! \n");
	for (auto p : this->c_get_all())
		o << p->to_string();
	for (auto p : this->c_get_special_storage())
		o << p->to_string();
}
