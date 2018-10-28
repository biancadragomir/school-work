#include "controller.h"
#include <assert.h>

void Controller::set_basket(Basket * b)
{
	this->basket = b;
}

//function used for adding a new coat via the controller
int Controller::controller_add(int size, const std::string color, int price, int quantity, const std::string photograph, int length)
{
	Trench_coat c{ size, color, price, quantity, photograph, length };
	this->validator.validate(c);
	return this->repo.repo_add_coat(c);
}

//function used for deleting a coat
int Controller::controller_delete(int size, const std::string photograph)
{
	return this->repo.repo_delete_coat(size, photograph);
}

int Controller::controller_update(int size, const std::string photograph, int new_quantity, int new_price)
{
	return this->repo.repo_update_coat(size, photograph, new_quantity, new_price);
}

int Controller::c_add_to_basket(int size, const std::string color, int price, int quantity, const std::string photograph, int length)
{
	Trench_coat c{ size, color, price, quantity, photograph, length };

	this->basket->basket_add_coat(c);
	this->basket->basket_add_to_price(c.get_price());
	return 1;
}

int Controller::c_update_coat(int size, const std::string photograph, int new_quantity, int new_price)
{
	return this->repo.repo_update_coat(size, photograph, new_quantity, new_price);
}

int Controller::c_update_basket_coat(int size, const std::string photograph, int new_quantity, int new_price)
{
	this->basket->basket_update_coat(size, photograph, new_quantity, new_price);
	return 1;
}

//int Controller::c_csv_add_to_basket(int size, const std::string color, int price, int quantity, const std::string photograph, int length)
//{
//	Trench_coat c{ size, color, price, quantity, photograph, length };
//
//	this->basket->basket_add_coat(c);
//	this->basket->basket_add_to_price(c.get_price());
//	return 1;
//}

//Basket * Controller::c_get_csv_basket()
//{
//	return this->basket;
//}