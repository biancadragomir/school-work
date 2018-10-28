#include "ui.h"
#include "client.h"
#include "agency.h"

int main()
{
	Agency a{};
	UI ui{ a };
	ui.run();
	return 0;
}