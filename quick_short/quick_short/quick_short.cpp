// quick_short.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#define M 12
using namespace std;
int L[]={29,35,42,17,39,12,25,54,10,72,19,85};

int splitPass(int *,int,int);
int _tmain(int argc, _TCHAR* argv[])
{
	int stacktop=-1,begin,end;
	int lbStacktop[M],ubStacktop[M];
	int n=M;
	if(n>0)
	{
		stacktop=0;
		lbStacktop[stacktop]=0;
		ubStacktop[stacktop]=n-1;
	}
	int loc;
	while(stacktop!=-1)
	{
		begin=lbStacktop[stacktop];
		end=ubStacktop[stacktop];
		stacktop=stacktop-1;
		loc=splitPass(L,begin,end);	
	
	if(begin<(loc-1)){
		stacktop=stacktop+1;
		lbStacktop[stacktop]=begin;
		ubStacktop[stacktop]=loc-1;
	}
	if(end>(loc+1)){
		stacktop=stacktop+1;
		lbStacktop[stacktop]=loc+1;
		ubStacktop[stacktop]=end;
	}
	}
	for(int i=0;i<n;i++)
		cout<<L[i]<<"\t";
	cout<<endl;
	for(int i=0;i<2;i++)
		cout<<lbStacktop[i]<<"\t";
		cout<<endl;
	for(int i=0;i<2;i++)
		cout<<ubStacktop[i]<<"\t";
		cout<<endl;
	system("pause");
	return 0;
}
int splitPass(int *L,int begin,int end){
	int left,right,loc;
bool flag;
	left=loc=begin; right=end;flag=false;
	while(!flag){
		while(L[loc]<=L[right]&&loc!=right){
			right=right-1;
		}
		if(loc==right){
			flag=true;
		}
		else if(L[loc]>L[right]){
			int temp=L[loc];
			L[loc]=L[right];
			L[right]=temp;
			loc=right;
		}
		while(L[loc]>=L[left]&&loc!=left){
		left=left+1;
		}
		if(loc==left){
			flag=true;
		}
		else if(L[loc]<L[left]){
			int temp=L[loc];
			L[loc]=L[left];
			L[left]=temp;
			loc=left;
		}
	}
		//for(int i=0;i<M;i++)
		//cout<<L[i]<<"\t";
	return(loc);
}

