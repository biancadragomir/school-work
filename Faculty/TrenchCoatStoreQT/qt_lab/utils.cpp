#include "utils.h"
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

//used for tokenizing a string
//output: a vector consisting of the components of the string in a way that we can use
std::vector<std::string> tokenize(const std::string & str, char delimiter)
{
	vector <string> result;
	string token;
	stringstream ss(str);
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}
