#include "team.h"

Team::Team()
{
	this->name = "";
	this->country = "";
	score = 0;
}

Team::Team(std::string name, std::string country, int score)
{
	this->name = name;
	this->country = country;
	this->score = score;
}

void Team::increase_score()
{
	this->score++;
}
