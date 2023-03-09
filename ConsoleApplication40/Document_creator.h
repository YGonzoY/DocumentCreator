#include <iostream>
#include <regex>
#include <string>

using namespace std;

class Document_creator
{
private:                      //храним полученные в конструкторе значения в объекте класса 
	string name;             //
	string sirname;         //
	string father_name;    //  отчество
public:
	Document_creator();
	int write_in_file();
};