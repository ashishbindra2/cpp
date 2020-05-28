// programm1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "time.h"
#include "stdlib.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int a[100],i;
	srand(1);
	for(i=0;i<100;i++){
		a[i]=rand()%100;
		cout<<a[i]<<"\t";	
		
	}
	system("pause");
	return 0;
}

