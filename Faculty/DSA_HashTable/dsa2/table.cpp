#include "table.h"
const int TABLE_SIZE = 100;
#include <iostream>
//constructor with parameters for the hash node

Hash_node::Hash_node(int _key, Student _value)
{

	this->key = _key;
	this->value.group = _value.group;
	this->value.name = _value.name;
}

Hash_node::Hash_node()
{
}


Deleted_node * Deleted_node::get_node()
{
	if (entry == NULL)
		entry = new Deleted_node();

	return entry;
}

Deleted_node* Deleted_node::entry = NULL;

Hash_map::Hash_map()
{
	hash_table = new Hash_node*[TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++)
		hash_table[i] = NULL;
}

Hash_map::~Hash_map()
{
	for (int i = 0; i < TABLE_SIZE; i++)
		if (hash_table[i] != NULL && hash_table[i] != Deleted_node::get_node())
			delete hash_table[i];
	delete[] hash_table;
}

int Hash_map::hash_function(int key)
{
	return key % TABLE_SIZE;
}

void Hash_map::insert(int key, Student value)
{
	int hash_value = hash_function(key);
	int init = -1;
	int del_index = -1;
	while (hash_value != init &&
		(hash_table[hash_value] == Deleted_node::get_node() || hash_table[hash_value] != NULL
			&& hash_table[hash_value]->key != key))
	{
		if (init == -1)
			init = hash_value;
		if (hash_table[hash_value] == Deleted_node::get_node())
			del_index = hash_value;
		hash_value = hash_function(hash_value + 1);
	}

	if (hash_value == init || hash_table[hash_value] == NULL)
	{
		if (del_index != -1)
			hash_table[del_index] = new Hash_node(key, value);
		else
			hash_table[hash_value] = new Hash_node(key, value);
	}

	if (init != hash_value)
	{
		if (hash_table[hash_value] != Deleted_node::get_node())
		{
			if (hash_table[hash_value] != NULL)
				if (hash_table[hash_value]->key == key)
				{
					hash_table[hash_value]->value.group = value.group;
					hash_table[hash_value]->value.name = value.name;
				}
			std::cout << "inserted " << hash_table[hash_value]->value.name << " from " 
				<< hash_table[hash_value]->value.group
				<< " at position " << hash_value << " more exactly with id " << hash_table[hash_value]->key << std::endl;

		}
		else
			hash_table[hash_value] = new Hash_node(key, value);
	}
}

Student Hash_map::search(int key)
{
	int hash_value = hash_function(key);
	int init = -1;
	while (hash_value != init &&
		(hash_table[hash_value] == Deleted_node::get_node() || hash_table[hash_value] != NULL &&
			hash_table[hash_value]->key != key))
	{
		if (init == -1)
			init = hash_value;
		hash_value = hash_function(hash_value + 1);
	}
	if (hash_table[hash_value] == NULL || hash_value == init)
	{
		const Student default_student = { -1, "" };
		return default_student;
	}
	else
		return hash_table[hash_value]->value;
}

void Hash_map::remove(int key)
{
	int hash_value = hash_function(key);
	int init = -1;
	while (hash_value != -1 &&
		(hash_table[hash_value] == Deleted_node::get_node() || hash_table[hash_value] != NULL && hash_table[hash_value]->key != key))
	{
		if (init == -1)
			init = hash_value;
		hash_value = hash_function(hash_value + 1);
	}
	if (hash_value != init && hash_table[hash_value] != NULL)
	{
		delete hash_table[hash_value];
		hash_table[hash_value] = Deleted_node::get_node();
	}
}

std::vector<int> Hash_map::get_keys()
{
	std::vector<int> keys;
	for (int i = 0; i <TABLE_SIZE; i++)
		if(hash_table[i] !=NULL)
			keys.push_back(this->hash_table[i]->key);
	return keys;
}

std::vector<Hash_node*> Hash_map::get_pairs()
{
	std::vector<Hash_node*> pairs;
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if(this->hash_table[i] != NULL)
		pairs.push_back(this->hash_table[i]);

	}
	return pairs;
}

Iterator::Iterator(Hash_map hash_map)
{
	this->hash_map = hash_map;
}

Hash_node Iterator::get_current()
{
	return this->current;
}
