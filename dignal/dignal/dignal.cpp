// dignal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "time.h"
#include "stdlib.h"

using namespace std;
inline int _tmain(int argc, _TCHAR* argv[])
{
	int a[10][10],i,j,s=0;
	srand(1);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		a[i][j]=rand()%10;
		s=s+a[i][j];
		cout<<a[i][j]<<" ";
		}
		cout<<"sum of row "<<i+" "<<s;
		cout<<endl;
	}
	cout<<"------------------"<<endl;	
	for(j=0;j<3;j++){
		for(i=0;i<3;i++){
		s=s+a[i][j];
	//	cout<<a[i][j]<<" ";
		}
		cout<<"sum of cola "<<j+" "<<s;
		cout<<endl;
	}
	system("pause");
	return 0;
}