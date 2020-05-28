// generic template.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namesapce std;

template <class t>
t Sum(t x,t y){
	return x+y;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<Sum(10,20)<<endl;
	cout<<Sum(2.5,3.75)<<endl;
	cout<<Sum(10,3.75)<<endl;
	cout<<Sum('A','B')<<endl;
	system("pause");
	return 0;
}

