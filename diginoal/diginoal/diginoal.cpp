// diginoal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "time.h"
#include "stdlib.h"
void pro1();
void pro2();
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cout<<"Enter the program number"<<endl;
	cin>>n;
	if(n==1)
     	pro1();
    if(n==2)
		 pro2(); 
	system("pause");
	return 0;
}
void pro1(){
	int i,j,c,r;
	int a[10][10];

	cout<<"Enter the numbers of rows and cols"<<endl;
	cin>>r>>c;
	srand((unsigned)time(NULL));
	if(r==c){
	for(i=0;i<c;i++){
		for(j=0;j<r;j++){
			a[i][j]=1+rand()%9;
			if(i==j||(i+j)==r-1)
	         	a[i][j]=0;
             cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	}
	else{
	  cout<<"row and cols must be same matrix must be square"<<endl;
	}
}
void pro2(){
	int i,j,c,r,q=0;
	int a[10][10],sum=0;

	cout<<"Enter the numbers of rows and cols"<<endl;
	cin>>r>>c;
	srand((unsigned)time(NULL));
	for(i=0;i<c;i++){			
		sum=0;
		for(j=0;j<r;j++){
			a[i][j]=1+rand()%9;
             cout<<a[i][j]<<"\t";
			  sum=sum+a[i][j];
		}
			cout<<sum<<endl;
			q=q+sum;
	}		
cout<<"----------------------------------------------------"<<endl;
	for(i=0;i<c;i++){
		sum=0;
		for(j=0;j<r;j++){
			 //cout<<a[i][j];
			sum=sum+a[j][i];
		}
		cout<<sum<<"\t"; \
				q=q+sum;
		//cout<<endl;
	}
		cout<<q<<endl;
}