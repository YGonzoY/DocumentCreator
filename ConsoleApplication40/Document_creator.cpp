#include <iostream>
#include <regex>
#include <string>
#include <fstream>

using namespace std;

class Document_creator
{
private:                      //������ ���������� � ������������ �������� � ������� ������ 
	string name;             //
	string sirname;         //
	string father_name;    //  ��������
public:
	Document_creator()
	{
		cout << "Enter name" << "\n";
		cin >> name;
		cout << "Enter sirname" << "\n";
		cin >> sirname;
		cout << "Enter fater_name" << "\n";
		cin >> father_name;
	}

	int write_in_file()
	{
		ifstream file("Zayav1.txt");
		if (!file.is_open())
		{
			cout << "���� �� ������\n\n";
			return -1;
		}
		else
		{
			cout << "��� ��! ���� ������!\n\n";
			return 1;
		}
		string buf;
		auto r = regex("FIO");
		while (getline(file, buf))
		{
			regex_replace(buf, r, sirname);
		}

		file.close();
	}
};