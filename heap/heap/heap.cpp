// heap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Heap.h"
#include "iostream"
#include "time.h"
using namespace std;
CHeap::CHeap()
{
	A=NULL;
	size=count=0;
}
CHeap::CHeap(int n)
{
	A=new int[n];
	size =n;
	count=0;
}
CHeap::~CHeap()
{
	if(A!=NULL)
		A=NULL;
	size=count=0;
}
}
bool CHeap::IsEmpty(){
	if(count==0)
		return true;
	return false;
}
bool CHeap::IsFull()
{}
int CHeap::GetParent(int index)
{
	return (index-1)/2;
}
void CHeap::GetChildresn(int index,int *LChild, int *RChil);
LChild=index*2+1;
RChild=index*2+2;
}


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}



CHeap::CHeap(void)
{
}


CHeap::~CHeap(void)
{
}
