#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
void CreateTXT(char* fname) 
{
	ofstream fout(fname); 
	char ch; 
	string s; 
	do
	{
		cin.get(); 
		cin.sync(); 
		cout << "enter line: "; getline(cin, s); 
		fout << s << endl; 
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}
void PrintTXT(char* fname)
{
	ifstream fin(fname); 
	if (!fname)
	{
		cerr << "Помилка при відкритті файлу " << endl;
		exit(1);
	}
	string s; 
	while (getline(fin, s)) 
	{
		cout << s << endl; 
	}
	cout << endl;
}

void Poradok(char* fname,char* gname)
{
	
	ifstream fin(fname);
	ofstream fout(gname);
	if (!fname)
	{
		cerr << "Помилка при відкритті файлу " << endl;
		exit(1);
	}
	string s;
	unsigned i = 1;
	while (getline(fin, s))
	{
		fout << i << " " << s << " " << s.length() << endl;
		i++;
	}
}

int main()
{
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char fname[100];
	char gname[100];
	char choice;

	do {
		cout << "Оберіть дію!" << endl << "[1] - Cтворити файл" << endl << "[2] - Додати елементи до файлу" << endl << "[3] - Переписати рядки файлу F до файлу Н" << endl << "[4] - Вивести результат перепису на екран " << endl  << "[0] - Вихід із програми" << endl << endl << endl;
		cout << "Ваш вибір : "; cin >> choice;
		switch (choice)
		{
		case '1':
			cout << "Enter file  : "; cin >> fname;
			break;
		case '2':
			cout << "Enter file  : "; cin >> fname;
			CreateTXT(fname);
			break;
		case '3':
			cout << "Enter file  : "; cin >> gname;
			Poradok(fname, gname);
			break;
		case '4':
			PrintTXT(gname);
			break;
		case '0':
			break;
		default:
			cout << "\nПомилка!\n\n";
			break;
		}
	} while (choice != '0');

	return 0;
}