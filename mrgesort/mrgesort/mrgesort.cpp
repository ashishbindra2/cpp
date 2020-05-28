// mrgesort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#define C 8
using namespace std;
int a[C]={41,35,17,8,13,44,5,28};
int b[] = {0};
int Lower = 0;
int Upper = C;
int mid =0;
int MergeLists(int , int ,int);
int MergeSorting(int,int);
int _tmain(int argc, _TCHAR* argv[])
{
	int x;
	x=	MergeSorting(Lower,Upper);
	cout<<x<<endl;
			for(int k=Lower;k<Upper;k++)
		cout<<a[k]<<"\t";
	system("pause");
	return 0;
}
int MergeSorting(int Lower, int Upper){
	int c;
	if(Upper > Lower)
	{
		mid = (Lower + Upper)/2;
		MergeSorting(Lower , mid);
		MergeSorting(mid + 1 , Upper);
	c=	MergeLists(Lower, mid, Upper);
	}
	return c;
}
int MergeLists(int Lower, int mid, int Upper){
	int Lb1 = Lower, Lb2 = mid + 1;
	int Ub1 = mid, Ub2 = Upper , k=1 ;
	while(Lb1 < Ub1 && Lb2 < Ub2)
	{
		if(a[Lb1] < a[Lb2])
		{
			b[k] = a[Lb1];
			Lb1 = Lb1 + 1;
			k = k + 1;
		}
		else
		{
			b[k] = a[Lb2];
			Lb2 = Lb2 + 1;
			k = k + 1;
		}
	}
	if(Lb1 > Ub1)
	{
		while(Lb2 <= Ub2)
		{
			b[k]  = a[Lb2];
			Lb2 = Lb2 + 1;
			k = k + 1;

		}
	}
	else
	{
		while(Lb1 < Ub1)
		{
			b[k] = a[Lb1];
			Lb1 = Lb1 + 1;
			k= k+1;
		}
	}
	for(k=Lower;k<Upper;k++)
		a[k] = b[k];

	return a;
}

