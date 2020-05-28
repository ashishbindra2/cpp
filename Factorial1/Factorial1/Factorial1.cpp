// Factorial1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;
int fact(int);
int i=1;
int _tmain(int argc, _TCHAR* argv[])
{
	int n,t;
    cout<<"Enter the factorial number---->";
    cin>>n;
	if(n<0)
		cout<<"invalid option"<<endl;
		t=fact(n);
	cout<<"factorial of "<<t<<endl;
		system("pause");
	return 0;
}
int fact(int f1){
	i=i*f1;
	f1--;
	if(f1>0)
		fact(f1);
	else
	  return 1;
	return i;
}

