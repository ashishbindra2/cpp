// genericprogram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

template <class t1, class t2>
t2 Sum(t1 x,t2 y){
	return x+y;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<Sum(10,20)<<endl;
	cout<<Sum(2.5,3.75)<<endl;
	cout<<Sum(10.5,3)<<endl;
	cout<<Sum('A','2')<<endl;
	system("pause");
	return 0;
}



