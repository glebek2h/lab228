#include "String.h"



String::String()
{
	maxlen = 200;
	/*char str[80];*/
	/*cout << endl << "¬ведите строку без пробелов " << endl;
	cin >> str;
	len = strlen(str);*/
	/*for (int i = 0; i < len; i++)
		s[i] = str[i];*/
	s = new char[len+1];
	s[len + 1] = '\0';
	
	
}

String::String(int size)
{
	maxlen = 200;
	len = size;
	s = new char[size];
}
String::String(const String &s)
{
	for (int i = 0; i < len; i++)
		this->s[i] = s.s[i];
}
String::~String()
{
	delete[] s;
}

istream & operator >>(istream & in, String & s1)
	{
		for (int i = 0; i < s1.len; i++)
			in >> s1.s[i];
		return in;
	}
ostream & operator <<(ostream & out, String & s1)
{
	for (int i = 0; i < s1.len; i++)
		out << s1.s[i];
	out << endl;
	return out;
}
String & operator +(String &s1,String &s2)
{
	int a = s1.len;
	int b = s2.len;
	s1.len = a + b;
	int count = 0;
	for (int i = 0; i <a+b; i++)
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
	for (int i = s.len-1; i >= 0; i--)
	{
		l.s[count] = s.s[i];
		count++;
	}
	for (int i = 0; i < count; i++)
		s.s[i] = l.s[i];
	return s;
}


