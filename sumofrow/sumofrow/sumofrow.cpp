// sumofrow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "time.h"
#include "stdlib.h"

using namespace std;
inline int _tmain(int argc, _TCHAR* argv[])
{
	int a[10][10],i,j,sum[10][10]={0};
	srand(1);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		a[i][j]=rand()%10;
		if(i==j||(i+j)==2)
			a[i][j]=0;
		cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}	
	system("pause");
	return 0;
}