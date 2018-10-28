#include "ui.h"

int main()
{
	Painting* p1, *p2;
	p1 = new Painting{ "painting1", "artist1", 1998 };
	p2 = new Special_painting{ "painting2", "artist2", 1990, 19 };
	Repository n{}; Repository s{};
	n.add_painting(p1); s.add_painting(p2);
	Controller c{ n, s };
	UI ui{ c };
	ui.run();
}