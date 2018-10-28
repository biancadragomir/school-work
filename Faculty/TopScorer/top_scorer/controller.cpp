#include "controller.h"
#include <string>
#include <assert.h>
#include <iostream>

//function that adds a new team to the repo
//input: the team to be added
//output:
//	1 - if the team is successfully added
//	0 - if the team is not added (if its name is already in the repo)
int Controller::c_add(std::string name, std::string country, int score)
{
	Team t = Team(name, country, 0);
	int ok = this->r.repo_add(t);
	return ok;
}

Team * Controller::c_get_repo()
{
	return this->r.get_all();
}

int Controller::c_get_repo_size()
{
	return this->r.repo_get_size();
}

int Controller::c_match(std::string team1, std::string team2, std::string winning)
{
	int ok = this->r.repo_match_teams(team1, team2, winning);
	return ok;
}

//function that sorts the teams descendingly by score
//input: none
//output: returns a list of entities sorted descendingly by their score
//calls the repo function associated to this action
Team * Controller::c_descending()
{
	Team* sort_entities = this->r.repo_descending();
	return sort_entities;
}

void test_sorted()
{
	Controller c;
	Repository r;
	Team t1 = Team("a", "b", 20);
	Team t2 = Team("b", "b", 10);
	Team t3 = Team("c", "b", 0);
	c.c_add("c", "b", 0);
	c.c_add("b", "b", 10);
	c.c_add("a", "b", 20);
	//Team * all = c.c_get_repo();
	//for (int i = 0; i < c.c_get_repo_size(); i++)
	//	std::cout << all[i].get_name() << std::endl;
	Team* ent = c.c_descending();
	//for (int i = 0; i < c.c_get_repo_size(); i++)
	//	std::cout << ent[i].get_name() << std::endl;
	//assert(ent[0].get_name() == t1.get_name());
	//assert(ent[1].get_name() == t2.get_name());
	//assert(ent[2].get_name() == t3.get_name());
}
