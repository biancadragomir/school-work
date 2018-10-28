#ifndef QT_LAB_H
#define QT_LAB_H

#include <QtWidgets/QMainWindow>
#include "ui_qt_lab.h"

class qt_lab : public QMainWindow
{
	Q_OBJECT

public:
	qt_lab(QWidget *parent = 0);
	~qt_lab();

private:
	Ui::qt_labClass ui;
};

#endif // QT_LAB_H
