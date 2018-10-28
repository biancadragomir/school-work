#include "chatwindow.hpp"
#include <qlineedit.h>


ChatWindow::ChatWindow(const User& u, ChatSession& session, QWidget * parent) :QWidget(parent), usr{u}, chat_session{session}
{
	set_window();
	this->chat_session.observers.push_back(this);
	this->chat_session.register_observer(this);
	connect(send_button, &QPushButton::clicked, this, &ChatWindow::send_message);
	connect(this->line_edit, &QLineEdit::returnPressed, this, &ChatWindow::send_message);
	this->setWindowTitle(QString::fromStdString(this->usr.get_user_name()));
}

ChatWindow::~ChatWindow()
{

}

void ChatWindow::send_message()
{
	std::string text = this->line_edit->text().toStdString();
	Message m{ text };
	UserMessage{ this->usr, m };
	this->chat_session.add_message(this->usr, m);
	this->line_edit->clear();
}

void ChatWindow::set_window()
{
	all_layout = new QVBoxLayout{ this };
	messages_list = new QListWidget;
	all_layout->addWidget(messages_list);
	line_edit = new QLineEdit{};
	QHBoxLayout* line_send_layout = new QHBoxLayout{};
	line_send_layout->addWidget(line_edit);
	this->send_button = new QPushButton{ "Send" };
	refresh_button = new QPushButton{ "refresh" };

	line_send_layout->addWidget(send_button);
	line_send_layout->addWidget(refresh_button);

	all_layout->addLayout(line_send_layout);

}

void ChatWindow::update()
{
	std::vector<UserMessage> messages = this->chat_session.get_messages();
	this->messages_list->clear();

	for (auto m : messages)
	{
		messages_list->addItem(QString::fromStdString(m.to_string()));
	}
}
