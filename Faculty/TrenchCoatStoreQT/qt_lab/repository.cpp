#include "repository.h"
#include <string>
#include <assert.h>
#include <fstream>
#include "repo_exceptions.h"

using namespace std;

Repository::Repository(const std::string & filename)
{
	this->filename = filename;
	this->read_from_file();
}

//add a coat to the repo
int Repository::repo_add_coat(const Trench_coat& c)
{
	if (repo_find_coat(c.get_size(), c.get_photograph()) != -1)
		throw DuplicateCoatException();
	else
	{
		this->coats.push_back(c);
		this->write_to_file();
		return 1;
	}
	return 0;
}

//find a coat from the repo
int Repository::repo_find_coat(const int&  size, const std::string& photograph)
{
	Trench_coat t1{ size, "", 0, 0, photograph, 0 };
	Trench_coat * repo_coats = this->coats.data();
	if (repo_coats == NULL)
		return -1;
	int i = 0;
	std::vector<Trench_coat>::iterator it = coats.begin();
	while (it != coats.end())
	{
		Trench_coat coat = repo_coats[i];
		if (coat == t1)
			return i;
		i++; it++;
	}
	return -1;
}

// deletes the coat
int Repository::repo_delete_coat(int size, const std::string photograph)
{
	int pos = repo_find_coat(size, photograph);
	if (pos == -1)
		return -1;
	this->coats.erase(coats.begin() + pos);
	this->write_to_file();
	cout << "writing to file";
	return 1;

}

//to udate the quantity and the price of a coat from the repo
int Repository::repo_update_coat(int size, const std::string photograph, int new_quantity, int new_price)
{
	int pos = repo_find_coat(size, photograph);
	if (pos == -1)
		return -1;
	this->coats[pos].set_quantity(new_quantity);
	this->coats[pos].set_price(new_price);
	this->write_to_file();
	return 1;
}

//function that returns the size of the dynamic array
int Repository::repo_get_size()
{
	return this->coats.size();
}

//void Repository::write_to_file()
//{
//	ofstream file(this->filename);
//	
//	Trench_coat t;
//	while (file << t)
//		this->coats.push_back(t);
//
//	file.close();
//}
//
//void Repository::read_from_file()
//{
//	ifstream file(this->filename);
//	for (auto t : this->coats)
//		file >> t;
//	file.close();
//}

void Repository::read_from_file()
{
	ifstream file(this->filename);

	if (!file.is_open())
		throw FileException("the file has not been opened! ");

	Trench_coat t;
	while (file >> t)
		this->coats.push_back(t);

	file.close();
}

void Repository::write_to_file()
{
	ofstream file(this->filename);

	if (!file.is_open())
		throw FileException("the file has not been opened! ");

	for (auto t : this->coats)
	{
		file << t;
	}

	file.close();
}