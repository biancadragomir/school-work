#pragma once
#include "controller.h"
class UI
{
private:
	Controller c;
	
public:
	UI() {};
	UI(Controller c_) { this->c = c_; };
	void ui_add();
	void ui_delete();
	void ui_see_all();
	void ui_write_file();
	void menu();
	void run();
};