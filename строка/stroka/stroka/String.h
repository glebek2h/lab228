#pragma once
#include <iostream>
#include <fstream>
using namespace std;
struct Bad_index{};
class String
{
	char * s;
	int maxlen, len;
public:
	String();
	String(int size);
	String(const String &s);
	~String();
	friend String & operator +(String &s1,String &s2);
	friend String & operator +=(String &s1, String &s2);
	
	const String& operator = (const String &s);
	friend String & operator ! ( String &s);
	bool operator == (const String &s);
	bool operator != (const String &s);
	bool operator > (const String &s);
	bool operator < (const String &s);
	bool operator >= (const String &s);
	bool operator <= (const String &s);
	friend istream & operator >>(istream & in, String & s1);
	friend ostream & operator <<(ostream & out, String & s1);
	char & operator [](int num);
};

