// selection_short.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int a[]={22,35,17,8,13,44,5,28};
	int min,temp,pos;
	bool flag;
	int size = sizeof(a)/sizeof(a[0]);
	//cout<<size<<endl;
	int n=size-1;
	cout<<"Before sorting:--->"<<endl;
	for(int k=0;k<n;k++){
		cout<<a[k]<<"\t";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		min=a[i]; flag=false;
		for(int j=i+1;j<n;j++){
			if(a[j]<min){	
				min=a[j]; 
			   flag=true;pos=j;
			   }
		}
		if(flag==true)
			{
					temp=a[i];
					a[i]=a[pos];
					a[pos]=temp;
			}
	}
	cout<<"After sorting---->"<<endl;
		for(int i=0;i<n;i++){\
			cout<<a[i]<<"\t";
		}
		cout<<endl;
	system("pause");
	return 0;
}


