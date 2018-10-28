#pragma once
#include <qwidget.h>
#include "controller.h"
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>

class GUI : public QWidget
{
	Q_OBJECT
private:
	Controller& ctrl;
	QListWidget * songWList;
	QPushButton* add;
	QPushButton* remove;

public:
	GUI(Controller& c, QWidget * parent = 0);
	~GUI();
	void set_window();
	void add_button_handler();
	void populate_list();
	Controller& get_controller() { return ctrl; }
};

