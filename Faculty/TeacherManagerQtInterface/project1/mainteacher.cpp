#include <qmessagebox.h>
#include "mainteacher.hpp"
#include <qlineedit.h>
MainTeacher::MainTeacher(Controller&c, QWidget * parent) : QWidget(parent), ctrl{ c } 
{
	this->set_window();
	this->populate_list();
	ctrl.register_observer(this);
	this->setWindowTitle("Main Teacher");
	connect(add_button, &QPushButton::clicked, this, &MainTeacher::add_student);
	connect(students_list, &QListWidget::currentItemChanged, this, &MainTeacher::fill_fields);
}

MainTeacher::~MainTeacher() {
	
}

void MainTeacher::update()
{
	this->populate_list();
}

void MainTeacher::set_window()
{
	this->main_layout = new QVBoxLayout{ this };
	this->students_list = new QListWidget{};
	this->main_layout->addWidget(students_list);

	this->add_layout = new QVBoxLayout{};
	this->add_button = new QPushButton{ "add" };
	this->add_form = new QFormLayout{};
	this->name_line = new QLineEdit{};
	this->id_line = new QLineEdit{};
	this->group_line = new QLineEdit{};
	this->grade_line = new QLineEdit{};

	this->add_form->addRow(id_line);
	this->add_form->addRow(name_line);
	this->name_line->setText("");
	this->add_form->addRow(group_line);
	this->add_form->addRow(grade_line);
	this->grade_line->setText("1");

	this->add_form->addRow("&id ", id_line);
	this->add_form->addRow("&name ", name_line);
	this->add_form->addRow("&group ", group_line);
	this->add_form->addRow("&grade ", grade_line);

	this->add_layout->addLayout(add_form);
	this->add_layout->addWidget(add_button);
	this->main_layout->addLayout(add_layout);

}

void MainTeacher::populate_list()
{
	std::vector<Student> students = this->ctrl.c_get_students();
	this->students_list->clear();
	for (auto s : students)
	{
		this-> students_list->addItem(QString::fromStdString(s.to_string()));
	}
}

void MainTeacher::add_student()
{
	try
	{
		int id, group; std::string name; double grade;
		id = stoi(id_line->text().toStdString());
		group = stoi(group_line->text().toStdString());
		name = name_line->text().toStdString();
		grade = stod(grade_line->text().toStdString());
		this->ctrl.c_add_student(Student{ id, name, group, grade });
		ctrl.notify();

	}
	catch (std::exception & e)
	{
		std::string message = "";
		message += "The id has already been used! ";
		QMessageBox::critical(nullptr, "Warning", QString::fromStdString(message), QMessageBox::Ok);
	}
	
}

void MainTeacher::fill_fields()
{
	std::vector<Student> students = ctrl.c_get_students();
	int i = students_list->currentRow();
	this->name_line->setText(QString::fromStdString(students[i].get_name()));
	
}


