// yale.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
void swap (int*a, int *b){
	int t=*a;
*a=*b;
*b=t;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int x=40, y=50;
	swap (x,y);
		cout<<x<<"\t"<<y;
	cout<<endl;
	system("pause");

	return 0;
}

