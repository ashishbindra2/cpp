// insertion_sort1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int temp,n=8,k;
	int a[]={22,35,17,8,13,44,5,25};
	for(int i=1;i<n;i++){
		temp=a[i];k=i-1;
		while(a[k]>temp && k>=0){
				a[k+1]=a[k];
				k=k-1;
		}
		a[k+1]=temp;
	}
	for(int i=0;i<n;i++){
	cout<<a[i]<<"\t";
	}
	cout<<endl;
	system("pause");
	return 0;
}

