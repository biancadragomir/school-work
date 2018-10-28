#include "ui.h"
#include <iostream>
#include <string>
using namespace std;

void UI::ui_add()
{
	try
	{
		std::string artist_, title_, ok_;
		bool is_special_; int year_;

		cout << "artist: "; getline(cin, artist_);
		cout << "title: "; getline(cin, title_);
		cout << "year: "; cin >> year_; cin.ignore();
		cout << "is it special? (y/n) - "; getline(cin, ok_);
		if (ok_ != "y" && ok_ != "n")
			throw exception("input y or n! \n");

		if (ok_ == "y")is_special_ = true;
		else is_special_ = false;

		this->c.c_add(artist_, title_, year_, is_special_);
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}
}

void UI::ui_delete()
{
	try
	{
		std::string artist_, title_; int year_;
		cout << "artist: "; getline(cin, artist_);
		cout << "title: "; getline(cin, title_);
		cout << "year: "; cin >> year_;
		this->c.c_remove_painting(artist_, title_, year_);
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}
}

void UI::ui_see_all()
{
	for (auto p : this->c.c_get_special_storage())
		cout << p->to_string();
	for (auto p : this->c.c_get_all())
		cout << p->to_string();
}

void UI::ui_write_file()
{
	try
	{
		std::string filename;
		cout << "introduce the filename : "; getline(cin, filename);
		this->c.c_write_to_file(filename);
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}
}

void UI::menu()
{
	cout << "these are the available commands: \n";
	cout << "1 - add a painting\n";
	cout << "2 - see all paintings\n";
	cout << "3 - remove a painting\n";
	cout << "4 - write to file\n";
	cout << "0 - exit\n";
}

void UI::run()
{
	int c;
	while (1)
	{
		this->menu();
		cout << "introduce your command: "; cin >> c; cin.ignore();
		if (c == 0)
			break;
		switch (c)
		{
		default:
			break;
		case 1:
			this->ui_add();
			break;
		case 2:
			this->ui_see_all();
			break;
		case 3:
			this->ui_delete();
			break;
		case 4:
			this->ui_write_file();
			break;
		}
	}
}
