#include "teacherwindow.hpp"

TeacherWindow::TeacherWindow(Controller & c, Teacher t, QWidget * parent) : QWidget(parent) , ctrl{c}, teacher{t}
{
	this->ctrl.register_observer(this);
	set_window();
	populate_list();
}

TeacherWindow::~TeacherWindow() {
	this->ctrl.unregister_observer(this);
}

void TeacherWindow::set_window()
{
	this->main_layout = new QVBoxLayout{ this };
	this->students_list = new QListWidget{};
	this->main_layout->addWidget(students_list);
}

void TeacherWindow::populate_list()
{
	this->students_list->clear();
	std::vector<int> groups = teacher.get_groups();
	std::vector<Student> students = ctrl.c_get_students();
	for (auto s : students)
	{
		int ok = 0;
		/*if (std::find(groups.begin(), groups.end(), s) != groups.end())
		{
			this->students_list->addItem(QString::fromStdString(s.to_string()));
		}*/
		for (int i = 0; i < groups.size(); i++)
		{
			if (s.get_group() == groups[i])
				ok = 1;
		}
		if(ok)
		this->students_list->addItem(QString::fromStdString(s.to_string()));
	}
}

void TeacherWindow::update()
{
	this->populate_list();
}

