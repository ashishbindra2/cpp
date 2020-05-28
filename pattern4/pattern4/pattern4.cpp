// pattern4.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int n,i,j,t,d;
	cout<<"Enter numbers of rows";
	cin>>n;
	for(i=1;i<=n;i++){
		t=i;d=n-1;
		for(j=1;j<=i;j++){
		cout<<t;
		t=t+d--;
			}
		cout<<endl;
	}
	system("pause");
	return 0;
}

