// moday_prog2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"iostream"

using namespace std;
void swap(int*,int*,int*);
int _tmain(int argc, _TCHAR* argv[])
{
	//int a[10]={11,43,76,34,56,87,89,};
	//int *ptr;
    int a,b,c,s;
	cout<<"Enter the values of a,b,c--->"<<endl;
	cin>>a>>b>>c;
	cout<<"values befor swap-->"<<a<<" "<<b<<" "<<c<<endl;
	swap(&a,&b,&c);
	cout<<"after swap"<<a<<" "<<b<<" "<<c<<endl;
	system("pause");
	return 0;
}
void swap(int *x,int *y,int *z){
	int temp;
	temp=*x;//temp=1
	*x=*z;//x=3
	*z=*y;//z=2
	*y=temp;//y=1
}
