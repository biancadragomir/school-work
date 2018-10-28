#include "ui.h"
#include <iostream>
#include <string>

using namespace std;

void UI::ui_add()
{
	std::string name, country;
	int score = 0;
	cout << "introduce the name of the team: "; getline(cin, name);
	cout << "introduce the country: "; getline(cin, country);
	if (this->c.c_add(name, country, score) == 0)
		cout << "cannot add team! " << endl;
	else cout << "successfully added the team! " << endl;
}



void UI::ui_print_all()
{
	Team * entities = this->c.c_get_repo();
	for (int i = 0; i < this->c.c_get_repo_size(); i++)
		cout << entities[i].get_name() << " | " << entities[i].get_country() << " | " << entities[i].get_score() << endl;
}

void UI::ui_match()
{
	std::string team1, team2, winning;
	while (1)
	{
		cout << "both teams are 0 if you want to exit! " << endl;
		cout << "introduce the first team: ";
		getline(cin, team1);
		cout << "introduce the second team: ";
		getline(cin, team2);
		if (team1 == "0" && team2 == "0")
			break;
		cout << "intorduce the winning team: ";
		getline(cin, winning);
		int ok = this->c.c_match(team1, team2, winning);
		if (ok == 1)
			cout << "success! ";
		else cout << "not successful! ";
	}
}

//function that shows the teams sorted descendingly by score
//input: none
//output: the teams are printed on the screen sorted descendingly by score
//bubble sort was used for sorting the teams
void UI::ui_descending()
{
	Team sort_entities[100];
	for (int i = 0; i < this->c.c_get_repo_size(); i++)
	{
		sort_entities[i] = Team("", "", 0);
		sort_entities[i].set_country(this->c.c_descending()[i].get_country());
		sort_entities[i].set_name(this->c.c_descending()[i].get_name());
		sort_entities[i].set_score(this->c.c_descending()[i].get_score());
	}

	//Team * sort_entities = this->c.c_descending();
	for (int i = 0; i < this->c.c_get_repo_size(); i++)
		cout << sort_entities[i].get_name() << " | " << sort_entities[i].get_country() << " | " << sort_entities[i].get_score() << endl;
}

void UI::ui_print_menu()
{
	cout << "these are the available commands: " << endl;
	cout << "1 - add a new team " << endl;
	cout << "2 - print all the teams " << endl;
	cout << "3 - repeatedly match teams " << endl;
	cout << "4 - print teams descendingly by score " << endl;
	cout << "0 - exit" << endl;
}

void UI::ui_run()
{
	while (1)
	{
		this->ui_print_menu();
		int c;
		cin >> c;
		cin.ignore();
		if (c == 0)
			break;
		switch (c)
		{
		case 1:
			this->ui_add();
			break;
		case 2:
			this->ui_print_all();
			break;
		case 3:
			this->ui_match();
			break;
		case 4:
			this->ui_descending();
			break;
		}
	}
}

