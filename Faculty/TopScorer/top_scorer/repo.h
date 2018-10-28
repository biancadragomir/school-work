#pragma once
#include "team.h"

class Repository
{
private:
	Team entities[100];
	int size;

public:
	//default constructor
	Repository() { this->size = 0; }
	Team* get_all() { return this->entities; }
	int repo_add(Team t);
	int repo_find(Team t);
	int repo_get_size() { return this->size; }
	int repo_match_teams(std::string team1, std::string team2, std::string winning);
	Team* repo_descending();
};

void test_add();