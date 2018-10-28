#pragma once
#include <QWidget>
#include <qlayout.h>
#include <qlistwidget.h>
#include "chatSession.h"
#include "subject.h"
#include "chatSession.h"
#include <qpushbutton.h>


class ChatWindow : public QWidget , public Observer
{
	Q_OBJECT

public:
	User usr;
	ChatSession &chat_session;

	ChatWindow(const User& u, ChatSession &session, QWidget * parent = Q_NULLPTR);

	~ChatWindow();
	void send_message();

	void set_window();
	QVBoxLayout* all_layout;
	QListWidget * messages_list;
	QLineEdit* line_edit;
	QPushButton* send_button;
	QPushButton* refresh_button;

	void update() override;

};