#pragma once
#include "trench_coat.h"
#include "dynamic_vector_template.h"
#include <vector>


class Repository
{
public:
	std::vector<Trench_coat> coats;

public:
	Repository() {};//the default constructor
	int repo_add_coat(const Trench_coat& c); // so i decided that the coats will be uniquely identified by size and photograph
	int repo_find_coat(const int& size, const std::string& photograph); // returns the position of the coat in the vector
	int repo_delete_coat(int size, const std::string photograph); // deletes the coat c from the repo
	int repo_get_size();
	int repo_update_coat(int size, const std::string photograph, int new_quantity, int new_price); //update a coat
																								   //void repo_set_size_at(int position, int size);
	int repo_get_size_at(int pos) { return this->coats[pos].get_size(); }

	std::vector<Trench_coat> repo_get_all() const { return coats; } // for getting all the coats from the repo

private:
	void write_to_file();
	void read_from_file();
};