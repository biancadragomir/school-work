#pragma once
#include "controller.h"
#include <QWidget>
#include "observer_and_subject.h"
#include <qlayout.h>
#include <qlistwidget.h>
#include <qformlayout.h>
#include <qpushbutton.h>

class MainTeacher : public QWidget, public Observer 
{
	Q_OBJECT

public:
	MainTeacher(Controller& c, QWidget * parent = Q_NULLPTR);
	~MainTeacher();
	Controller &ctrl;
	void update() override;
	void set_window();
	void populate_list();
	QVBoxLayout* main_layout;
	QListWidget* students_list;
	void add_student();
	QVBoxLayout* add_layout;
	QPushButton* add_button;
	QFormLayout* add_form;
	QLineEdit* id_line;
	QLineEdit* group_line;
	QLineEdit* grade_line;
	QLineEdit* name_line;

	void fill_fields();


private:
	
};
