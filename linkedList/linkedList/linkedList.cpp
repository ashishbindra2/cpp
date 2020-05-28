// linkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "LINK.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	CLINK L;
	L.insertB(5);
	L.travers();

	L.insertE(10);
	L.travers();
	
	L.insertE(10);
	L.travers();

	L.insertE(20);
	L.travers();

	L.insertE(30);
	L.travers();

	L.deleteB();
	L.travers();

	L.deleteE();
	L.travers();
	L.freq();
	system("pause");
	return 0;
}

