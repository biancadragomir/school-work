#pragma once
#include <iostream>
#include <string>
class Team
{
private:
	std::string name, country;
	int score;

public:
	Team();
	Team(std::string name, std::string country, int score);
	int get_score() { return score; }
	std::string get_name() { return name; }
	std::string get_country() { return country; }
	void increase_score();

	void set_name(std::string new_name) { this->name = new_name; }
	void set_score(int new_score) { this->score = new_score; }
	void set_country(std::string new_country) { this->country = new_country; }
};