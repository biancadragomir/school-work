#pragma once
#include "user_repo.h"
#include <string>

class CSV_basket : public Basket
{
public:
	CSV_basket();
	CSV_basket(std::string filename);
	int basket_add_coat(const Trench_coat & t);

	void user_write_to_file() override;
	void user_read_from_file() override;
	void open_basket() override;
};