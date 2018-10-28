#include "ui.h"
#include <string>
#include <iostream>
using namespace std;
void UI::ui_add_client()
{
}
void UI::ui_add_dwelling()
{
	std::string type, prof; double price; bool profitable;
	cout << "introduce the type of the dwelling: ";
	getline(cin, type);
	cout << "price: "; cin >> price; cin.ignore();
	cout << "is it profitable? y/n\n"; getline(cin, prof);
	if (prof == "y")
		profitable = true;
	else
		profitable = false;
	Dwelling d = this->agency.add_dwelling(type, price, profitable);
	cout << "interested clients: \n";
	for (auto c : this->agency.get_clients())
	{
		if (c->is_interested(d))
			cout << c->to_string();
	}
}
void UI::ui_delete_client()
{
	std::string name;
	cout << "introduce the name of the client: " << endl;
	getline(cin, name);
	try
	{
		this->agency.remove_client(name);
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}
}
void UI::ui_write_to_file()
{
	string filename;
	cout << "introduce the name of the file: ";
	getline(cin, filename);
	this->agency.write_to_file(filename);
	cout << "the clients have been written to the file! \n";
}

void UI::print_menu()
{
	cout << "these are the available commands:\n";
	cout << "1 - add a client\n";
	cout << "2 - see all the clients\n";
	cout << "3 - remove a client\n";
	cout << "4 - see all the dwellings\n";
	cout << "5 - add a dwelling\n";
	cout << "6 - save clients to a file\n";
	cout << "0 - exit\n";
}

void UI::run()
{
	int c;
	Client *c1, *c2, *c3;
	c1 = new Normal_client("jones", 10000);
	c2 = new Wealthy_client("smith", 100000, 1000);
	c3 = new Normal_client("rex", 200000);
	agency.add_dwelling("house", 100000, true);
	agency.add_dwelling("market", 50000, true);
	agency.add_dwelling("land", 1000, false);

	agency.add_client(c1);
	agency.add_client(c2);
	agency.add_client(c3);
	while (1)
	{
		print_menu();
		cout << "introduce your command: "; cin >> c; cin.ignore();
		if (c == 0)break;
		switch (c)
		{
		default:
			break;
		case 1:
			this->ui_add_client();
			break;
		case 2:
			this->ui_see_clients();
			break;
		case 3:
			this->ui_delete_client();
			break;
		case 4:
			this->ui_see_dwellings();
			break;
		case 5:
			this->ui_add_dwelling();
			break;
		case 6:
			this->save_to_file();
			break;
		}
	}
}

void UI::ui_see_clients()
{
	for (auto c : this->agency.get_clients())
		cout << c->to_string();
}

void UI::ui_see_dwellings()
{
	cout << "type | price | profitable" << endl;
	for (auto d : this->agency.get_dwellings())
		cout << d.dwell_string();
}

void UI::save_to_file()
{
	std::string filename;
	cout << "filename: ";
	getline(cin, filename);
	this->agency.write_to_file(filename);
}