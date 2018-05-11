#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include "CONTAINER.h"
using namespace std;
int& countStud(istream &in)
{
	char *str = new char[1024];
	int count = 0;
	while (!in.eof())
	{
		in.getline(str, 1024, '\n');
		count++;
	}
	delete str;
	return count;
}
int compare(const void * x1, const void *x2)
{
	return (*(int*)x1 - *(int*)x2);
}

void main()
{
	setlocale(LC_ALL, "rus");

	cout << " Container1:" << endl;
	ifstream in1("Text.txt");
	int count1 = countStud(in1);
	in1.clear();
	in1.seekg(0);
	CONTAINER <Container1> C1(count1);
	in1 >> C1;
	cout << " " << C1;

	cout << endl << " Container2:" << endl;
	ifstream in2("Input.txt");
	int count2 = countStud(in2);
	in2.clear();
	in2.seekg(0);
	CONTAINER <Container2> C2(count2);
	in2 >> C2;
	cout << " " << C2;

	try
	{
		int count3 = 0;
		for (int i = 0; i < count1; i++)
		{
			for (int j = 0; j < count2; j++)
			{
				if (strcmp(C1[i].Name, C2[j].Name) == 0)
				{
					count3++;
				}
			}
		}
		CONTAINER <Container3> C3(count3);
		C3.Sum(C1, C2);
		cout << endl << " Cтуденты ,которые и в С1 и в С2(поместили их в С3):" << endl << " " << C3;

		int key = 0;
		cout << endl << " Введите номер группы,студентов который вы хотите узнать" << endl;
		cin >> key;
		classmates(C2, key);

		sort_by_groups(C1);
		cout << endl << " Контейнер С3 после сортировки :" << endl << " " << C1;




		cout << endl;
		system("pause");
	}
	catch (Bad_index)
	{
		cout << endl << "Bad index" << endl;
	}
}