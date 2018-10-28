#include "ui.h"
#include <iostream>
#include "table.h"

using namespace std;
UI::UI()
{
}

void UI::menu()
{
	std::cout << "these are the available commands: \n";
	std::cout << "\t0 - exit\n";
	cout << "\t1 - insert a new student\n";
	cout << "\t2 - search for a student\n";
	cout << "\t3 - delete a student\n";
	cout << "\t4 - get keys\n";
	cout << "\t5 - get pairs\n";
}