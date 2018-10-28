#include "qt_lab.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <conio.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "csv_basket.h"
#include "repo_exceptions.h"
#include "repository.h"
#include "gui.h"
#include "guidesigner.h"


using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo("coats.txt");
	Controller ctrl{ repo };
	GUI g{ ctrl };

	g.show();
	return a.exec();
}


//
//int main()
//{
//	//Tests::test_all(); 
//
//	try
//	{
//		Repository repo("coats.txt");
//		Controller ctrl { repo };
//		UI ui{ ctrl };
//		ui.run();
//
//		cout << "bye! " << endl;
//	}
//	catch (FileException& e)
//	{
//		cout << "Repository file could not be opened! The application will terminate." << endl;
//		return 1;
//	}
//
//	//_CrtDumpMemoryLeaks();
//
//	return 0;
//}