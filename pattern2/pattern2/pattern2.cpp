// pattern2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int n,i,j,k=2,l=1;
	cout<<"Enter numbers of rows";
	cin>>n;
	for(i=1;i<=n;i++){
		for(j=0;j<i;j++){
			if((i%2)==0){
			   cout<<k;
			   	k=k+2;
			}
			else{
				cout<<l;
				l=l+2;
			}	
		
		}
		
		cout<<endl;
	}
	system("pause");
	return 0;
}

