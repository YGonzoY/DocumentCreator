#include <iostream>
#include <regex>
#include <string>

using namespace std;

class Document_creator
{
private:                      //������ ���������� � ������������ �������� � ������� ������ 
	string name;             //
	string sirname;         //
	string father_name;    //  ��������
public:
	Document_creator();
	int write_in_file();
};