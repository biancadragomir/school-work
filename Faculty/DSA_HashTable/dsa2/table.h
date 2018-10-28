#pragma once
#include <string>
#include <vector>

typedef struct Student
{
	int group;
	std::string name;
};

//declaration for a hash node
class Hash_node
{
public:
	int key; //which is going to be the group number
	Student value; // the student is going to be the assigned value of the node
	Hash_node(int _key, Student _value);
	Hash_node();
};

//deleted node class declaration
class Deleted_node : public Hash_node
{
private:
	static Deleted_node* entry;

	//the constructor for a deleted node is going to call the constructor for a hash node having the key -1 and the student also default
	Deleted_node() :Hash_node(-1, Student() ) {};

public:
	static Deleted_node* get_node();
};

//hash map class declaration
class Hash_map
{
private:
	Hash_node ** hash_table;

public:

	Hash_map();
	~Hash_map();

	int hash_function(int key);

	//function for inserting a new element in the hash table
	void insert(int key, Student value);

	//function for searching an element being given the key
	Student search(int key);

	//function for removing an element using its key
	void remove(int key);

	//function that will return a vector containing the keys of the map
	std::vector<int> get_keys();

	//function that will return the pairs from the map
	std::vector<Hash_node*> get_pairs();
	

};

class Iterator
{
private:
	Hash_map hash_map;
	Hash_node current;

public:
	Iterator(Hash_map hash_map);
	Hash_node get_current();
	bool is_valid(int key);

};