#include "repo.h"
#include <assert.h>

//function that adds a new team to the repo
//input: the team to be added
//output:
//	1 - if the team is successfully added
//	0 - if the team is not added (if its name is already in the repo)

int Repository::repo_add(Team t)
{
	if (this->repo_find(t) == 0)
	{
		this->entities[size] = t;
		size++;
		return 1;

	}
	return 0;
}

int Repository::repo_find(Team t)
{
	for (int i = 0; i < this->size; i++)
		if (this->entities[i].get_name() == t.get_name())
			return 1;
	return 0;
}

int Repository::repo_match_teams(std::string team1, std::string team2, std::string winning)
{

	Team* entities = this->entities;
	Team t1, t2;
	for (int i = 0; i < this->size; i++)
		if (entities[i].get_name() == team1)
			t1 = entities[i];
	for (int i = 0; i < this->size; i++)
		if (entities[i].get_name() == team2)
			t2 = entities[i];
	if (t1.get_score() != t2.get_score())
		return 0;
	for (int i = 0; i < this->size; i++)
		if (entities[i].get_name() == winning)
			this->entities[i].increase_score();
	return 1;
}

//sorts the entities descendingly by score
Team * Repository::repo_descending()
{
	//Team sort_list[100];
	//for (int i = 0; i < this->size; i++)
	//{
	//	sort_list[i] = Team("", "", 0);
	//	sort_list[i].set_country(this->entities[i].get_country());
	//	sort_list[i].set_name(this->entities[i].get_name());
	//	sort_list[i].set_score(this->entities[i].get_score());
	//}
	Team * sort_list = this->get_all();

	int ok = 0;
	while (ok == 0)
	{
		ok = 1;
		for (int i = 0; i<this->size - 1; i++)
			for (int j = i + 1; j<this->size; j++)
				if (sort_list[i].get_score() < sort_list[j].get_score())
				{
					Team aux = sort_list[i];
					sort_list[i] = sort_list[j];
					sort_list[j] = aux;
					ok = 0;
				}
	}
	return sort_list; // returns the sorted entities
}

void test_add()
{
	Team t1 = Team("a", "b", 0);
	Team t2 = Team("c", "d", 0);
	Team t3 = Team("a", "x", 0);

	Repository r1;
	assert(r1.repo_get_size() == 0);
	r1.repo_add(t1);
	assert(r1.repo_get_size() == 1);
	r1.repo_add(t2);
	assert(r1.repo_get_size() == 2);
	r1.repo_add(t3);
	assert(r1.repo_get_size() == 2);
}
