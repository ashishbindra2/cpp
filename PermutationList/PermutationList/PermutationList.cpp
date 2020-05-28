// PermutationList.cpp : Defines the entry point for the console application.
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
	per(str,0,n-1);//2,0,1
	cout<<endl;
		system("pause");
	return 0;
}
void per(char *a,int l,int r){
	if(l==r){
          cout<<a<<endl;	
	}
	else{
		int i;
	 for(i=l;i<=r;i++){
	    swap(a+l,a+i);
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