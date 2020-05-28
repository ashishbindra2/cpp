// pattern1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

void pattrn1();
void pattrn2();
void pattrn3();
int _tmain(int argc, _TCHAR* argv[])
{
	int prog;
	cout<<"Enter program no"<<endl;
	cin>>prog;
	if(prog==1)
	{
		pattrn1();
	}
	else if(prog==2){
	void pattrn2();
	}
	else if(prog==3){
	void pattrn3();
	}
	system("pause");
	return 0;
}
void pattrn1()
{
		int n,i,j;
	cout<<"Enter numbers of rows"<<endl;
	cin>>n;
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
		    cout<<j;
		}
		cout<<endl;
	}
	
}
void pattrn2()
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

