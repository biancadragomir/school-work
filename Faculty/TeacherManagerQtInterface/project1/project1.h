#ifndef PROJECT1_H
#define PROJECT1_H

#include <QtWidgets/QMainWindow>
#include "ui_project1.h"

class project1 : public QMainWindow
{
	Q_OBJECT

public:
	project1(QWidget *parent = 0);
	~project1();

private:
	Ui::project1Class ui;
};

#endif // PROJECT1_H
