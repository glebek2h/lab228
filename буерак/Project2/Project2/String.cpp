#include "String.h"
#define _CRT_NO_WARNINGS
#include <cmath>
#include<cstdlib>
String::String()
{
	maxlen = 200;
}

String::String(int size)
{
	maxlen = 200;
	len = size;
	s = new char[size];
	//s[size + 1] = '\0';
}
String::String(const String &s)
{
	for (int i = 0; i < len; i++)
		this->s[i] = s.s[i];
}
String::~String()
{
	//delete[] s;/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

istream & operator >>(istream & in, String & s1)
{
	char str[80];
	cout << endl << "¬ведите строку без пробелов " << endl;
	in >> str;
	s1.len = strlen(str);
	s1.s = new char[s1.len];
	for (int i = 0; i < s1.len; i++)
		s1.s[i] = str[i];
	s1.s[s1.len] = '\0';
	return in;
}
ostream & operator <<(ostream & out, String & s1)
{
	for (int i = 0; i < s1.len; i++)
		out << s1.s[i];
	out << endl;
	return out;
}
String & operator +(String &s1, String &s2)
{
	int a = s1.len;
	int b = s2.len;
	s1.len = a + b;
	int count = 0;
	for (int i = 0; i <a + b; i++)
	{
		if (i < a)
			s1.s[i] = s1.s[i];
		if (i >= a)
		{
			s1.s[i] = s2.s[count];
			count++;
		}
	}
	return s1;
}
const String& String::operator = (const String &s)
{
	if (&s != this)
	{
		len = s.len;
		for (int i = 0; i < len; i++)
			this->s[i] = s.s[i];
	}
	return *this;
}
bool String::operator == (const String &s)
{
	if (len != s.len)
		return false;
	for (int i = 0; i < len; i++)
		if (this->s[i] != s.s[i])
			return false;
	return true;
}
bool String::operator != (const String &s)
{
	if (len != s.len)
		return true;
	for (int i = 0; i < len; i++)
		if (this->s[i] != s.s[i])
			return true;
	return false;
}
bool String::operator > (const String &s)
{
	if (len > s.len)
		return true;
	return false;
}
bool String::operator < (const String &s)
{
	if (len < s.len)
		return true;
	return false;
}
bool String::operator >= (const String &s)
{
	if (len >= s.len)
		return true;
	return false;
}
bool String::operator <= (const String &s)
{
	if (len <= s.len)
		return true;
	return false;
}
char & String::operator [](int num)
{
	if (num > len || num < 0)
		throw Bad_index();
	else
		return s[num];
}


String & operator +=(String &s1, String &s2)
{
	int a = s1.len;
	int b = s2.len;
	s1.len = a + b;
	int count = 0;
	for (int i = 0; i <a + b; i++)
	{
		if (i < a)
			s1.s[i] = s1.s[i];
		if (i >= a)
		{
			s1.s[i] = s2.s[count];
			count++;
		}
	}
	return s1;
}
String & operator ! (String &s)
{
	String l(s.len);
	int count = 0;
	for (int i = s.len - 1; i >= 0; i--)
	{
		l.s[count] = s.s[i];
		count++;
	}
	for (int i = 0; i < count; i++)
		s.s[i] = l.s[i];
	return s;
}
bool String::isnum()
{
	for (int i = 0; i < len; i++)
		if (isdigit(s[0]) == 0)
			return false;
	return true;
}
int func(char c)
{
	switch (c)
	{
	case '1':return 1; case '2':return 2; case '3':return 3; case '4':return 4; case '5':return 5; case '6':return 6; case '7':return 7; case '8':return 8; case '9':return 9;
	}
}
int & String::atois()
{
	int *res = new int[len];
	int count = 0, first, lol;
	int ten = 10, countten = 0;
	if (this->isnum())
	{
		for (int i = 0; i < len; i++)
		{
			if (i >= 1)
			{
				res[countten] = res[countten - 1] * ten + func(s[i]);
				countten++;
			}
			else
			{
				res[countten] = func(s[i]);
				countten++;
			}
			lol = i;
		}
		if (lol == 1)
			return first;

		return res[len - 1];
	}
	else throw Bad_index();
}
double & String::atofs()
{
	double res;
	res = atof(s);
	return res;
}
//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
String & String::operator() (String & a)
{
	String buf(a.len);
	for (int i = 0; i < a.len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (a[i] == s[j])
			{
				for (int l = j, count = 0; l < a.len + j, count < a.len; l++, count++)
					buf.s[count] = s[l];
				if (buf == a)
				{
					buf.s[buf.len] = '\0';//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					return buf;
				}
			}
		}
	}
	throw Bad_index();
}
String & String::operator()(int begin, int end, String & a)
{
	String buf(a.len);
	for (int i = 0; i < a.len; i++)
	{
		for (int begin = 0; begin < end; begin++)
		{
			if (a[i] == s[begin])
			{
				for (int l = begin, count = 0; l < a.len + begin, count < a.len; l++, count++)
					buf.s[count] = s[l];
				if (buf == a)
					return buf;
			}
		}
	}
	throw Bad_index();
}