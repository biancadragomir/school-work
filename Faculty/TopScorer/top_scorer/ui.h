#pragma once
#include "controller.h"

class UI
{
public:
	Controller c;

public:
	void ui_add();
	void ui_print_menu();
	void ui_run();
	void ui_print_all();
	void ui_match();
	void ui_descending();
};