#include "student.h"
#include <sstream>

using namespace std;
int Student::get_id()
{
	return id;
}

int Student::get_group()
{
	return group;
}

std::string Student::to_string()
{
	stringstream ss;
	ss << id << " - " << name << " (" << group << "): " << grade;
	return ss.str();

}

std::string Student::to_file()
{
	stringstream ss;
	ss << id << "," << name << "," << group << "," << grade << "\n";
	return ss.str();
}

std::string Student::get_name()
{
	return name;
}

//bool Student::operator==(const Student   s)


std::vector<int> Teacher::get_groups()
{
	return groups;	
}

StudentException::~StudentException()
{
}

const char * StudentException::what()
{
	return this->message.c_str();
}
