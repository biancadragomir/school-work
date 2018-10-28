#pragma once
#include "user_repo.h"
#include <string>

class HTML_basket : public Basket
{

public:
	HTML_basket();
	HTML_basket(std::string filename);

	void user_write_to_file() override;
	void user_read_from_file() override;

	int basket_add_coat(const Trench_coat& c);
	void open_basket() override;
};