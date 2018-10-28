#include <fstream>
#include <sstream>
#include "repository.h"
using namespace std;

Repository::Repository(std::string sf, std::string tf)
	: students_file{sf}, teachers_file{tf}
{
	read_from_file();
}

void Repository::read_from_file()
{
	ifstream sf(students_file);
	string line;
	while (getline(sf, line))
	{
		stringstream ss(line);
		string token;
		vector<string> result;

		while (getline(ss, token, ','))
		{
			result.push_back(token);
		}
		Student s{ stoi(result[0]), result[1], stoi(result[2]), stod(result[3]) };
		students.push_back(s);
	}
	sf.close();
	ifstream tf(teachers_file);
	while (getline(tf, line))
	{
		std::stringstream ss(line);
		std::vector<string> result;
		std::string token;
		while (getline(ss, token, ','))
		{
			result.push_back(token);
		}
		std::vector<int> groups;
		for (int i = 1; i < result.size(); i++)
		{
			groups.push_back(stoi(result[i]));
		}
		Teacher t{ result[0], groups };
		this->teachers.push_back(t);

	}
}

void Repository::write_to_file()
{
	ofstream f(students_file);
	for (auto s : students)
	{
		f << s.to_file();
	}
	f.close();
}

std::vector<Student> Repository::get_students()
{
	return students;
}

std::vector<Teacher> Repository::get_teachers()
{
	return teachers;
}

int Repository::add_student(Student s)
{
	int ok = 1;
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i].get_id() == s.get_id())
			ok = 0;
	}
	if (ok)
	{
		students.push_back(s);

		write_to_file();
		return 1;
	}
	else
		throw std::exception();

	
}
