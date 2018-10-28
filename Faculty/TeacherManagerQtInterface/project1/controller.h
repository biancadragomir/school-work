#pragma once
#include "repository.h"
#include "observer_and_subject.h"

class Controller : public Subject
{
private:
	Repository repo;

public:
	Controller(){}
	~Controller(){}
	Controller(Repository r):repo{r}{}

	std::vector<Student> c_get_students();
	std::vector<Teacher> c_get_teachers();
	int c_add_student(Student s);
};