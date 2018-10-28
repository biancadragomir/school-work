#pragma once
#include <vector>
#include "student.h"

class Repository
{
private:
	std::vector<Student> students;
	std::vector<Teacher> teachers;
	std::string students_file, teachers_file;

public:
	Repository(std::string sf, std::string tf);
	Repository(){}
	~Repository(){}
	void read_from_file();
	void write_to_file();
	std::vector<Student> get_students();
	std::vector<Teacher> get_teachers();
	int add_student(Student s);
	
};