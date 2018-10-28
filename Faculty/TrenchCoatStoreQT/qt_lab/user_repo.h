#pragma once
#include "trench_coat.h"
#include <vector>

class Basket
{
public:
	std::vector<Trench_coat> coats;
	int current_price;
	std::string filename;

public:
	Basket() {};//the default constructor
	Basket::Basket(const std::string & filename);
	virtual int basket_add_coat(const Trench_coat& c); // so i decided that the coats will be uniquely identified by size and photograph
	int basket_find_coat(const int& size, const std::string& photograph); // returns the position of the coat in the vector
																		  //int basket_delete_coat(int size, const std::string photograph); // deletes the coat c from the repo
	int basket_get_size();
	void basket_add_to_price(int price);
	int basket_get_price() { return this->current_price; }
	int Basket::basket_update_coat(int size, const std::string photograph, int new_quantity, int new_price);

	std::vector<Trench_coat> basket_get_all() const { return coats; } // for getting all the coats from the repo
	virtual void user_write_to_file() = 0;
	virtual void user_read_from_file() = 0;
	virtual void open_basket() = 0;
};
//void test_repo();