// ConsoleApplication40.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <locale>
//#include <locale.h>                    //с этими строками русский ввод корректен, а вывод в файл - нет
//#include <cstdlib>                    //с этими строками русский ввод корректен, а вывод в файл - нет
//#include "Document_creator.h"
using namespace std;



class Document_creator
{
private:                      //храним полученные в конструкторе значения в объекте класса 
	string name;             //
	string sirname;         //
	string father_name;    //  отчество
public:
	Document_creator()
	{
		//setlocale(LC_ALL, "Russian");         //с этими строками русский ввод корректен, а вывод в файл - нет
		//system("chcp 1251");                 //с этими строками русский ввод корректен, а вывод в файл - нет
		cout << "Enter name" << "\n";
		cin >> name;
		cout << "Enter sirname" << "\n";
		cin >> sirname;
		cout << "Enter fater_name" << "\n";
		cin >> father_name;
		write_in_file();
	}

	void write_in_file()
	{
		//_setmode(_fileno(stdout), _O_U16TEXT);
		//setlocale(LC_ALL, "Russian");
		ifstream file("Zayav2.txt");
		ofstream new_file("Zayav2_" + sirname + "_31.12.2022.txt");
		if (!file.is_open())
		{
			cout << "File is not open\n\n";
			//return -1;
		}
		else
		{
			cout << "File is open\n\n";
			//return 1;
		}
		string buf;
		auto r = regex("FIO");
		cout << "regex created\n";
		while (getline(file, buf))
		{
			cout << "got line\n";
			cout << regex_replace(buf, r, get_full_name());
			new_file << regex_replace(buf, r, get_full_name());
			new_file << "\n";
			cout << "replaced\n";
		}

		file.close();
	}

	string get_full_name()
	{
		string c = sirname;
		c += " ";
		c += name[0];
		c += ".";
		c += " ";
		c += father_name[0];
		c += ".";
		return c;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
    Document_creator a;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
