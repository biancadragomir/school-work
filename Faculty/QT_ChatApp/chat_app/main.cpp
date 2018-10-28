#include "chat_app.h"
#include <QtWidgets/QApplication>
#include "chatwindow.hpp"
#include "user.h"
#include <assert.h>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//chat_app w;
	//w.show();
	ChatSession s{};
	s.add_message(User{ "user2", "frank" }, Message{ "abcd" });
	ChatWindow cw1{ User{"user1", "frank"}, s };
	ChatWindow cw2{ User{"user2", "steve"}, s };
	ChatWindow cw3{ User{ "cortana", "cortana" }, s };

	cw2.chat_session.add_message(User{ "user2", "steve" }, Message{ "hello world" });
	cw1.update();
	cw2.update();
	/*assert(cw1.chat_session.observers.size() == 1);
	assert(cw2.chat_session.observers.size() == 1);*/

	//cw2.messages_list->addItem("hello");
	cw1.show();
	cw2.show();
	cw3.show();
	return a.exec();
}
