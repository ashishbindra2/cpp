// pattern3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int n,i,j,k;
	cout<<"Enter numbers of rows";
	cin>>n;
	for(i=0;i<n;i++){
		for(k=n;k>i;k--){
		cout<<" ";
		}
		for(j=0;j<=i;j++){
			
			cout<<"*";
		}
		for(j=1;j<=i;j++){
			
			cout<<"*";
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}

