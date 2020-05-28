// stl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <list>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	list<int>L;
	for(int i=0; i<10; i++)
		L.push_back(i);
	list<int>::iterator p1,p2;
	p1=L.begin();
	while(p1!=L.end())
	{
		cout<<*p1<<"\t";
		p1++;
	}
	for(int i=0; i<10; i++)
		L.push_front(i*i);
		p2=L.begin();
	while(p2!=L.end())
	{
		cout<<*p2<<"\t";
		p2++;
	}
	system("pause");
	return 0;
}

