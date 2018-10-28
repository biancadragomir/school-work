#pragma once
#include "repo.h"
#include <string>
#include <vector>
class Controller
{
private:
	Repository repo_all, special_storage;

public:
	Controller() {};
	Controller(Repository repo_all_, Repository special_storage_);

	void c_add(std::string artist_, std::string title_, int year_, bool is_special_);
	void c_remove_painting(std::string artist_, std::string title_, int year_);
	std::vector<Painting*> c_get_all();
	std::vector<Painting*> c_get_special_storage();
	void c_write_to_file(std::string filename);
};