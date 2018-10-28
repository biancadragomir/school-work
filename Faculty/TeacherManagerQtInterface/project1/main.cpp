#include "project1.h"
#include <QtWidgets/QApplication>
#include "mainteacher.hpp"
#include "teacherwindow.hpp"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo{ "s.txt", "t.txt" };
	Controller ctrl{ repo };
	MainTeacher mt{ ctrl };
	mt.show();
	for (auto t : ctrl.c_get_teachers())
	{
		TeacherWindow * tw = new TeacherWindow(ctrl, t);
		tw->show();
	}

	//project1 w;
	//w.show();
	return a.exec();
}
