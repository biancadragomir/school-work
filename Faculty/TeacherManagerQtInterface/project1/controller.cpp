#include "controller.h"

std::vector<Student> Controller::c_get_students()
{
	return repo.get_students();
}

std::vector<Teacher> Controller::c_get_teachers()
{
	return this->repo.get_teachers();
}

int Controller::c_add_student(Student s)
{
	return repo.add_student(s);
}
