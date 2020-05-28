// dynamicprogfibb.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
class Fib
{
	int S[50];
public:
	Fib(){
		for (int i=0; i<50; i++)
			S[i]=0;
	}
	int DoesSolutionExist(int n){
		if(S[n]>0)
			return S[n];
		return 0;
	}
		unsigned int GetTermDP(unsigned int n)
		{ 
			if(n==0)
				return 0;
			if(n==2)
				return 1;
			if (DoesSolutionExist(n))
				return S[n];
			S[n]=GetTermDP(n-1)+GetTermDP(n-2);
				return S[n];		
         }
		unsigned int GetTerm(unsigned int n)
		{ 
		if(n==0)
			return 0;
		if(n==2)
			return 1;
		S[n]= GetTerm(n-1)+GetTerm(n-2);
		return S[n];
        }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Fib f;
	for(unsigned int i=0; i<=48; i++)
	{
		cout<<f.GetTermDP(i)<<"\t";
		cout<<f.GetTerm(i)<<"\t";
		cout <<endl;
	}
	system("pause");
	return 0;
}

