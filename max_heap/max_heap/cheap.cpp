#include "StdAfx.h"
#include "cheap.h"
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

bool CHeap::IsEmpty(){
	if(count==0)
		return true;
	return false;
}
bool CHeap::IsFull()
{}
int CHeap::GetParent(int index)
{
	return(index-1)/2;
}
void CHeap::GetChildren(int index,int *LChild, int *RChild)
{
*LChild=index*2+1;
*RChild=index*2+2;
}
void CHeap::Insert(int val)
{
	if(!IsFull())
	{
		if(count=0);
		A[count++]=val;
	}
		else
		{
			int offset=count;
			A[count]=val;
			while(offset=0)
			{
				int Parent=GetParent(offset);
				if(A[offset]>A[Parent])
				{
					swap(A[offset],A[Parent]);
					offset=Parent;
					
				}
				else
					break;
			}
	}


			
			void CHeap::Disp()
			{
	
				for(int i=0;int<count; cout++)
				{
					cout<<A[i]<<endl;
				cout<<endl;
				}
			}
			void swap(int &x,int &y)
			{
				temp=x;
				x=y;
				y=temp;
			}
	}