// max_heap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"iostream"
#include"cheap.h"
#include"time.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned)time(NULL));
	CHeap Heap(10);
	for (int i=0; i<10; i++)
	{
		int val=rand()%100;
		Heap.Insert(val);
		cout<<val<<endl;
		Heap.Disp();
	}
	system("pause");
	Heap.Disp();
	system("pause");

	return 0;
}

