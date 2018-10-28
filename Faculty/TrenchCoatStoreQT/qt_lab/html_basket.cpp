#include "html_basket.h"
#include <fstream>
#include "repo_exceptions.h"
#include <Windows.h>
using namespace std;

HTML_basket::HTML_basket()
{
}

HTML_basket::HTML_basket(std::string filename)
{
	this->filename = filename;
	this->user_write_to_file();

}

void HTML_basket::user_write_to_file()
{
	ofstream file(this->filename);

	if (!file.is_open())
		throw FileException("the file has not been opened! ");
	file << "<!DOCTYPE html>" << endl;
	file << "<html>" << endl;
	file << "<head>" << endl;
	file << "<title>Basket</title>" << endl;
	file << "</head>" << endl;
	file << "<body>" << endl;
	file << "<table border='1'>" << endl;
	file << "<tr>" << endl;
	file << "<td>" << "Size" << "</td>" << endl;
	file << "<td>" << "Color" << "</td>" << endl;
	file << "<td>" << "Price" << "</td>" << endl;
	//file << "<td>" << "Quantity" << "</td>" << endl;
	file << "<td>" << "Photo" << "</td>" << endl;
	file << "<td>" << "Length" << "</td>" << endl;

	for (auto t : this->coats)
	{
		file << "<tr>" << endl;
		file << "<td>" << t.get_size() << "</td>";
		file << "<td>" << t.get_color() << "</td>";
		file << "<td>" << t.get_price() << "</td>";
		//file << "<td>" << t.get_quantity() << "</td>";
		file << "<td><a href =" << t.get_photograph() << ">Link</a></td>";
		file << "<td>" << t.get_length() << "</td>";


		file << "</tr>" << endl;
	}
	file << "</table>" << endl;
	file << "</body>" << endl;
	file << "</html>" << endl;
	file.close();
}

void HTML_basket::user_read_from_file()
{
	ifstream file(this->filename);
	if (!file.is_open())
		throw FileException("the file has not been opened! ");

	Trench_coat t;
	while (file >> t)
		this->coats.push_back(t);

	file.close();
}

int HTML_basket::basket_add_coat(const Trench_coat & c)
{
	this->coats.push_back(c);
	this->user_write_to_file();
	return 1;
}

void HTML_basket::open_basket()
{
	string name = "C:\\Users\\Bianca\\Documents\\Visual_Studio_2015\\Projects\\lab_5_6\\lab_5_6\\html_basket.html";
	string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
	ShellExecuteA(NULL, NULL, "chrome.exe", name.c_str(), NULL, SW_SHOWMAXIMIZED);
}
