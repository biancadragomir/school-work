#pragma once
#include <exception>
#include <string>
#include <vector>

class Student
{
private:
	int id, group;
	double grade;
	std::string name;

public:
	int get_id();
	Student(){}
	~Student(){}
	Student(int id_, std::string name_, int group_, double grade_)
		: id{ id_ }, name{ name_ }, group{ group_ }, grade{ grade_ } {}
	int get_group();
	std::string to_string();
	std::string to_file();
	std::string get_name();

	bool operator==(const Student  s) {
		return id == s.id && name == s.name && group == s.group&& grade == s.grade;
	}

};

class Teacher
{
private:
	std::string name;
	std::vector<int> groups;

public:
	Teacher(std::string name_, std::vector<int> gr): name{name_}, groups{gr}{}
	Teacher(){}
	~Teacher(){}
	std::vector<int> get_groups();

};

class StudentException : public std::exception
{
protected:
	std::string message;
public:
	StudentException(){}
	StudentException(std::string m) { this->message = m; }
	~StudentException();
	virtual const char* what();
};