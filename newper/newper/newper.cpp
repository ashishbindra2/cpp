// newper.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;
void per(int[],int,int);
int _tmain(int argc, _TCHAR* argv[])
{
	char str[]="ABC";
	int n=strlen(str);
	per(str,0,n-1);//"ABC",0,1
	cout<<endl;
		system("pause");
	return 0;
}
void per(char *a,int l,int r){//"012",0,1
	if(l==r){
          cout<<a<<endl;	
	}
	else{
		int i;
	 for(i=l;i<=r;i++){//l=0,r=1
	    swap(a+l,a+i);//012,012//
	    per(a,l+1,r);
	    swap(a+l,a+i);
	    }
	}
}
void swap(char *x,char *y){
	char temp;
	temp=*x;
	*x=*y;
	*y=temp;

}