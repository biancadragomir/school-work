#pragma once
#include "agency.h"

class UI
{
private:
	Agency agency;

public:
	UI() {};
	UI(Agency a) { agency = a; };
	void ui_add_client();
	void ui_add_dwelling();
	void ui_delete_client();
	void ui_write_to_file();
	void print_menu();
	void run();
	void ui_see_clients();
	void ui_see_dwellings();
	void save_to_file();

};