//����������� ����,7 ������
#include <iostream>
using namespace std;
#include "String.h"
#define _CRT_NO_WARNINGS
void main()
{

	setlocale(LC_ALL, "rus");

	String s1, s2, s3;
	cin >> s1 >> s2;

	try {
		if (s1 != s2)
			cout << endl << "s1 is not equal s2" << endl;
		else cout << endl << "s1 is equal s2" << endl;

		if (s1 > s2)
			cout << endl << "s1 > s2" << endl;
		else cout << endl << "s1 <= s2" << endl;


		s3 = s1(s2); // londalondon london                               - ������ �� ���������� ��������� ( �� ������ �� ������ )
		cout << s3;
		
		
		s3 = s1(5, 15, s2);
		cout << s3;

		int res = s1.atois();
		cout << "�� char* � int -" << res << endl;
		double res1 = s1.atofs();
		cout << "�� char* � double -" << res1 << endl;


		cout << " �������� ��������������: " << s1[1] << endl;
		s1 += s2;
		cout << "s1 += s2  s1=" << s1 << endl;
		cout << "s1 +s2 =" << s1 + s2 << endl;
		cout << endl << "������ s2 �������� : " << !s2 << endl;


		if (s1.isnum())
			cout << endl << "�������� ������ ������� �� ����!" << endl;


	}
	catch (Bad_index)
	{
		cout << endl << "Bad_index" << endl;
	}


	system("pause");
}