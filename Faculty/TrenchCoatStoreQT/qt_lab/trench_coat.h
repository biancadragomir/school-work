#pragma once
#include<iostream>

class Trench_coat
{
private:
	int size;
	int price;
	int quantity;
	std::string color;
	std::string photograph;
	int length;
public:
	int get_size() const { return size; }
	int get_price() const { return price; }
	int get_quantity() const { return quantity; }
	int get_length() const { return length; }
	std::string get_color() const { return color; }
	std::string get_photograph() const { return photograph; }
	int set_size(int new_size);

	Trench_coat(); // the default constructor
	Trench_coat(int size, const std::string& color, int price, int quantity, const std::string& photograph, int length); //constructor with parameters

	int set_quantity(int new_quantity) { quantity = new_quantity; return 1; }
	void set_price(int new_price) { price = new_price; }

	//lab activity
	int operator==(const Trench_coat& t1);
	int open_photo();

	//lab 6 activity
	int operator<(int nr);

	friend std::istream& operator >> (std::istream& is, Trench_coat& t);
	friend std::ostream& operator << (std::ostream& os, const Trench_coat& t);
};

//void test_coat();

