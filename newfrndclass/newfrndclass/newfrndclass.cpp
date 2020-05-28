// newfrndclass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
class beta;
class alpha
{
private:
	int data1;
public:
	alpha():data1(99){}
	friend beta;
};
class beta
{
public:
	void fun1(alpha a)
	{
		cout<<"data1="<<a.data1;
	}


int _tmain(int argc, _TCHAR* argv[])
{
	alpha a;
	beta b;
	b.fun1(a);
	return 0;
}
}