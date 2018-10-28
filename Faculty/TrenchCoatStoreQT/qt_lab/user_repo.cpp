#include "user_repo.h"
#include <string>
#include "repo_exceptions.h"
#include <assert.h>
#include <fstream>

using namespace std;

Basket::Basket(const std::string & filename)
{
	this->filename = filename;
	//this->user_write_to_file();

	//this->user_read_from_file();
}

int Basket::basket_add_coat(const Trench_coat& c)
{
	this->coats.push_back(c);
	this->user_write_to_file();
	return 1;
}

//find a coat from the repo
int Basket::basket_find_coat(const int&  size, const std::string& photograph)
{
	Trench_coat t1{ size, "", 0, 0, photograph, 0 };
	Trench_coat * repo_coats = this->coats.data();
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
//
//// deletes the coat
//int Basket::basket_delete_coat(int size, const std::string photograph)
//{
//	int pos = basket_find_coat(size, photograph);
//	if (pos == -1)
//		return -1;
//	this->coats.vector_delete(pos);
//	return 1;
//
//}

//function that returns the size of the dynamic array
int Basket::basket_get_size()
{
	return this->coats.size();
}

void Basket::basket_add_to_price(int price)
{
	this->current_price += price;
}

int Basket::basket_update_coat(int size, const std::string photograph, int new_quantity, int new_price)
{
	int pos = basket_find_coat(size, photograph);
	if (pos == -1)
		return -1;
	Trench_coat t{ size, this->coats.at(pos).get_color(), new_price, new_quantity, photograph, this->coats.at(pos).get_length() };
	this->coats.assign(pos, t);
	return 1;
}

//void Basket::user_write_to_file()
//{
//	ofstream file(this->filename);
//
//	if (!file.is_open())
//		throw FileException("the file has not been opened! ");
//
//	for (auto t : this->coats)
//	{
//		file << t;
//	}
//
//	file.close();
//}
//
//void Basket::user_read_from_file()
//{
//	ifstream file(this->filename);
//	if (!file.is_open())
//		throw FileException("the file has not been opened! ");
//
//	Trench_coat t;
//	while (file >> t)
//		this->coats.push_back(t);
//
//	file.close();
//}