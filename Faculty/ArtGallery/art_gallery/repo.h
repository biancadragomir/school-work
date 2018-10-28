#pragma once

#include "domain.h"
#include <vector>
class Repository
{
private:
	std::vector<Painting*> paintings;

public:
	void add_painting(Painting* p);
	void remove_painting(Painting* p);
	std::vector<Painting*> get_all();
	void write_to_file(std::string filename);
	bool exists(Painting* p);
};