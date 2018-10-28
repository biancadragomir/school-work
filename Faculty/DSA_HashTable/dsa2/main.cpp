#include "ui.h"
#include "table.h"
#include <iostream>

using namespace std;

int main()
{
	UI ui{};
	Hash_map hash_map{};
	
	int cmd;
	while (true)
	{
		ui.menu();

		cout << "introduce your command: ";
		cin >> cmd; cin.ignore();
		if (cmd == 0)
			break;
		int id, group;
		string name;
		Student element;
		switch (cmd)
		{
		case 1:
			cout << "introduce the id of the student: ";
			cin >> id; cin.ignore();
			cout << "introduce the name of the student: ";
			getline(cin, name);
			cout << "introduce the group of the student: ";
			cin >> group;
			element.group = group;
			element.name = name;

			hash_map.insert(id, element);

			break;
		case 2:
			cout << "introduce the id of the student you want to find: ";
			cin >> id;
			cin.ignore();
			if (hash_map.search(id).group == -1)
			{	
				cout << "there is no entry with that id! \n";
				break;
			}
			cout << "student " << hash_map.search(id).name << " from group " << 
				hash_map.search(id).group << endl;
			break;
		case 3:
			cout << "introduce the id of the student you want to delete: ";
			cin >> id;
			cin.ignore();
			hash_map.remove(id);
			cout << "the student has been removed! \n";
			break;
		case 4:
			if (hash_map.get_keys().size() == 0)
			{
				cout << "there are no elements in the table at the moment! \n";
				break;
			}
			for (int i = 0; i < hash_map.get_keys().size(); i++)
				cout<< hash_map.get_keys()[i]<<endl;
			break;

		case 5:
			if (hash_map.get_keys().size() == 0)
			{
				cout << "there are no elements in the table at the moment! \n";
				break;
			}
			for (int i = 0; i < hash_map.get_pairs().size(); i++)
				cout << hash_map.get_pairs()[i]->key << " - " << hash_map.get_pairs()[i]->value.name << " (" << hash_map.get_pairs()[i]->value.group << ") \n";
			break;
		default:
			cout << "That command does not exist! \n";
			break;

		}
	}
	return 0;
}