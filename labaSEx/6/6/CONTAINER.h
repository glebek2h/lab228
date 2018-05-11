#pragma once
#pragma once
#include <iostream>
#include <fstream>
using namespace std;
struct Bad_index {};
struct Container1
{
	char Name[50];
	int  kurs;
	int  group;
	char  Otdelenie[15];
	friend ostream & operator << (ostream & out, const Container1 & C1)
	{
		out << C1.Name << " " << C1.kurs << " " << C1.group << " " << C1.Otdelenie << endl;
		return out;
	}
	friend istream & operator >> (istream & in, Container1 & C1)
	{
		in >> C1.Name >> C1.kurs >> C1.group >> C1.Otdelenie;
		return in;
	}

};
struct Container2
{
	char Name[50];
	int group;
	char  Otdelenie[15];
	friend ostream & operator << (ostream & out, const Container2 & C1)
	{
		out << C1.Name << " " << C1.group << " " << C1.Otdelenie << endl;
		return out;
	}
	friend istream & operator >> (istream & in, Container2 & C1)
	{
		in >> C1.Name >> C1.group >> C1.Otdelenie;
		return in;
	}

};
struct Container3
{
	char Name[50];
	int  kurs;
	int  group;
	char  Otdelenie[15];
	friend ostream & operator << (ostream & out, const Container3 & C1)
	{
		out << C1.Name << " " << C1.kurs << " " << C1.group << " " << C1.Otdelenie << endl;
		return out;
	}
	friend istream & operator >> (istream & in, Container3 & C1)
	{
		in >> C1.Name >> C1.kurs >> C1.group >> C1.Otdelenie;
		return in;
	}

};

template<class T>
class CONTAINER
{
	int count;
	T *M;
public:
	CONTAINER()
	{
		count = 30;
		M = new T[count];
	}
	CONTAINER(int a)
	{
		count = a;
		M = new T[count];
	}
	CONTAINER(CONTAINER <T> & m)
	{
		count = m.count;
		for (int i = 0; i < count; i++)
			M[i] = m.M[i];
	}
	~CONTAINER()
	{
		delete[] M;
	}
	friend ostream & operator << (ostream & out, const CONTAINER <T> &m)
	{
		for (int i = 0; i < m.count; i++)
			out << m.M[i] << " ";
		return out;
	}
	friend istream & operator >> (istream & in, CONTAINER <T> & m)
	{
		for (int i = 0; i < m.count; i++)
			in >> m.M[i];
		return in;
	}
	T & operator[](int key)
	{
		if (key<0 || key >count)
			throw Bad_index();
		else
			return M[key];
	}
	friend void classmates(CONTAINER <T> &C1, int key)
	{
		cout << "Cтуденты группы " << key << ":" << endl;
		for (int i = 0; i < C1.count; i++)
		{
			if (C1[i].group == key)
				cout << C1[i];
		}
	}
	friend void sort_by_groups(CONTAINER <T> &C1)
	{
		for (int i = 0; i < C1.count - 1; i++)
			if (C1[i].group > C1[i + 1].group)
				swap(C1[i], C1[i + 1]);
	}
	int get_count() {
		return count;
	}
	
	void Sum(CONTAINER < Container1> &C1, CONTAINER <Container2> &C2)
	{
		int count4 = 0;
		for (int i = 0; i < C1.get_count(); i++)
		{
			for (int j = 0; j < C2.get_count(); j++)
			{
				if (strcmp(C1[i].Name, C2[j].Name) == 0)
				{
					strcpy(M[count4].Name, C1[i].Name);
					M[count4].group = C1[i].group;
					M[count4].kurs = C1[i].kurs;
					strcpy(M[count4].Otdelenie, C1[i].Otdelenie);
					count4++;
				}
			}
		}
	}
};
