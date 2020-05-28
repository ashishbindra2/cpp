// shellSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#define n 12
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int gap =n/2;
	int i,temp,j;
	int a[]={64,85,20,55,9,17,97,88,49,71,27,30};
	while(gap >= 1)
	{
		i=gap ;
		while(i < n)
		{
			temp = a[i];
			j = i;
			while(j >= gap && a[j-gap] > temp)
			{
				a[j] = a[j-gap];
				j = j - gap;
			}
			a[j] = temp;
			i = i + 1;
		}
		gap = gap/2;
	}
	for(int k =0 ;k <n ; k++)
		 cout<<a[k]<<"\t";
	cout<<endl;
	system("pause");
	return 0;
}

