#ifndef GUIDESIGNER_H
#define GUIDESIGNER_H

#include <QWidget>
//#include "ui_guidesigner.h"

class GUIDesigner : public QWidget
{
	Q_OBJECT

public:
	GUIDesigner(QWidget *parent = 0);
	~GUIDesigner();

private:
	//Ui::GUIDesigner ui;
};

#endif // GUIDESIGNER_H
