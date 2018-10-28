#pragma once
#include <QWidget>
#include "observer_and_subject.h"
#include <qlistwidget.h>
#include <qlayout.h>
#include "controller.h"
class TeacherWindow : public QWidget, public Observer 
{
	Q_OBJECT

public:
	TeacherWindow(Controller& c,Teacher t, QWidget * parent = Q_NULLPTR);
	~TeacherWindow();

private:
	Controller& ctrl;
	Teacher teacher;

	void set_window();
	void populate_list();
	void update() override;
	QVBoxLayout* main_layout;
	QListWidget * students_list;

};
