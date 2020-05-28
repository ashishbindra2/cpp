// functionoverloading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
int add(int a,int b=20)
{
	return(a+b);
}
double add(double a, double b=1.5, double c=2.5)
{return(a+b+c);}
int add(int a=10, double b=2.5, double c=1.2)
{return(a+b+c);
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<(10)<<endl;
	cout<<(2.5)<<endl;
	cout<<(20)<<endl;
	system("pause");

	return 0;
}

