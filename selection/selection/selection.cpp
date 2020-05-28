// selection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int size, a[50], i, j, min,pos;
	cout<<"enter array size";
	cin>>size;
	cout<<"enter array element:";
		for(i=0; i<size; i++)
		{
			cin>>a[i];
		}
		cout<<"sorting array using selection sort";
		for(i=0; i<size-1; i++)
		{
			min=a[i];
			pos=i;
			for(j=size+1; j<size; j++)
			{
				if(min>a[j])
				{
					min=a[j];
					pos=j;
				}
			}
			swap(a[i], a[pos]);
		}			
		cout<<"now the array after sorting is:\n";
		for(i=0; i<size; i++)
		{
			cout<<a[i]<<" ";
		system("pause");
	return 0;
}

