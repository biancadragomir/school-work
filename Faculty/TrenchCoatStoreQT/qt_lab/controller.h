#pragma once
#include "repository.h"
#include "user_repo.h"
#include "coat_validator.h"
#include "csv_basket.h"
#include "html_basket.h"

class Controller
{
public:
	Repository repo;
	Basket *basket;
	Coat_validator validator;

public:
	Controller(const Repository& r) : repo(r) {}

	Repository get_repo() const { return repo; }
	Basket* get_basket() const { return basket; }
	void set_basket(Basket * b);
	int controller_add(int size, const std::string color, int price, int quantity, const std::string photograph, int length);
	int controller_delete(int size, const std::string photograph);
	int controller_update(int size, const std::string photograph, int new_quantity, int new_price);
	int c_add_to_basket(int size, const std::string color, int price, int quantity, const std::string photograph, int length);
	int c_update_coat(int size, const std::string photograph, int new_quantity, int new_price);
	int c_update_basket_coat(int size, const std::string photograph, int new_quantity, int new_price);
};