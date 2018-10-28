#ifndef CHAT_APP_H
#define CHAT_APP_H

#include <QtWidgets/QMainWindow>
#include "ui_chat_app.h"

class chat_app : public QMainWindow
{
	Q_OBJECT

public:
	chat_app(QWidget *parent = 0);
	~chat_app();

private:
	Ui::chat_appClass ui;
};

#endif // CHAT_APP_H
