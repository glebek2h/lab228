/*������� ����� "������" � ��������������, ������������, ��������������� ����� (�� char * � int, double � ��������), 
,,,,,��������� !,,,,,, () - ����������� ���������.

��������  ������� (����� ��������� �������� � ����������� ��) ������ ��������� (������� � ������ � � �����), ������� � ������ ������ ������ � �������� �������, 
��������� ��������� ������ �� ������ �������� � ������.*/
#include <iostream>
using namespace std;
#include "String.h"

void main()
{

	setlocale(LC_ALL, "rus");
	String s1(80), s2(80), s3;
	cin >> s1 >> s2;
	cout << s1 << s2;
	
	try {
		if (s1 != s2)
			cout << endl << "s1 is not equal s2" << endl;
		else cout << endl << "s1 is equal s2" << endl;

		if (s1 > s2)
			cout << endl << "s1 > s2" << endl;
		else cout << endl << "s1 <= s2" << endl;

		cout << " �������� ��������������: " << s1[1] << endl;
		s1 += s2;
		cout << s1;
		cout << s1 + s2;
		cout << endl << !s2;
	}
	catch (Bad_index)
	{
		cout << endl << "Bad_index" << endl;
	}


	system("pause");
}