#include "ui.h"

int main()
{
	test_add();
	test_sorted();
	Repository r;
	Controller c;
	UI ui;
	ui.c.c_add("larvik", "norway", 0);
	ui.c.c_add("csm", "ro", 0);
	ui.c.c_add("csm1", "ro", 0);
	ui.c.c_add("csm2", "ro", 0);
	ui.c.c_add("buducnost", "m", 0);
	ui.c.c_add("csm3", "ro", 0);

	ui.ui_run();
	return 0;
}