#include "gui.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <qpushbutton.h>
#include <QMessageBox>
//#include "addwidget.h"

GUI::GUI(Controller& c, QWidget *parent)
	: QWidget(parent), ctrl{ c }
{
	set_window();
	this->populate_list();
	connect(this->add, &QPushButton::clicked, this, &GUI::add_button_handler);
	//connect(this->filterEdit, &QLineEdit::textChanged, this, &GUI::PopulateList);
}

GUI::~GUI()
{
}

void GUI::set_window()
{
}

void GUI::add_button_handler()
{
}

void GUI::populate_list()
{
}
