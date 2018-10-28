#ifndef ADDWIDGET_H
#define ADDWIDGET_H

#include <QWidget>
//#include "ui_addwidget.h"
#include "Controller.h"
#include "gui.h"

class AddWidget : public QWidget
{
	Q_OBJECT

public:
	AddWidget(GUI *parent = 0);
	~AddWidget();

private:
	//UI::AddWidget ui;
	GUI* parent;
	void add_coat();
};

#endif // ADDWIDGET_H
