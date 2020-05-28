// vvvvvvv.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "iostream"
#define M 5
using namespace std;
int splitPass(int[],int,int);
int _tmain(int argc, _TCHAR* argv[])
{
	int stacktop=-1;
	int n,begin,end,loc;
	int lbs[M],ubs[M];
	int L[]={5,22,4,1,9};
	n=M-1;
	if(n>1)
	{
		stacktop = 0;
		lbs[stacktop]=1;
		ubs[stacktop] = n;
	}
	while(stacktop!=-1)
	{
		begin = lbs[stacktop];
		end = ubs[stacktop];
		stacktop=stacktop-1;
		loc = splitPass(L,begin,end);
		if(begin < loc - 1)
		{
			stacktop = stacktop - 1;
			lbs[stacktop] = begin;
			ubs[stacktop] = loc - 1;  
		}
		if(end > loc + 1)
		{
			stacktop = stacktop + 1;
			lbs[stacktop] = loc + 1;
			ubs[stacktop] = end;
		}
	}
	for(int i = 0;i < M;i++)
		cout<<L[i]<<endl;
	system("pause");
	return 0;
}
int splitPass(int L[],int begin,int end)
{
	int left,right,loc,temp;
	bool flag;
	left = begin; right = end; loc = begin; flag = false;
	while(flag==false)
	{
		while(L[loc] <= L[right] && loc != right)
		{
			right=right-1;
		}
		if(loc==right)
		{
			flag = true;
		}
		else if(L[loc] > L[right])
		{
			temp = L[loc];
			L[loc] = L[right];
			L[right] = temp;
			loc = right;
		}
		while(L[loc] >= L[left] && loc!= left)
		{
			left = left + 1;
		}
		if(loc == left)
		{
		    flag = true;
		}
		else if(L[loc] < L[left])
		{
			temp = L[loc];
			L[loc] = L[left];
			L[left] = temp;
			loc = left;
		}
	}
	return (loc);
}
