#pragma once
#include "repo.h"

class Controller
{
public:
	Repository r;

public:
	int c_add(std::string name, std::string country, int score);
	Team* c_get_repo();
	int c_get_repo_size();
	int c_match(std::string team1, std::string team2, std::string winning);
	Team * c_descending();
};

void test_sorted();
