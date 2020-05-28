// doublelinked.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "DLINK.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{ 
	DLINK D;
	D.insertAt_B(1);
	D.traversB();
	D.insertAt_E(2);
	D.traversB();
	D.insertAt_E(3);
	D.traversB();
	D.insertAt_E(4);
	D.traversB();
	D.deleteAt_E();
	D.traversB();
    D.deleteAt_B();
	D.traversB();
	aD.traversE();
	system("pause");
	return 0;
}

