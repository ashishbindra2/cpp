// bubble short.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    
int list [5] , i ;
* list  =  5 ;//list[0]=5
for  ( i=1;  i<5 ; i++ )
*(list +i) = *(list + i - 1) * i;//lis[1]=5*1,5*2
for ( i=0; i <5 ; i++){
printf("%d", list [i]) ;
cout<<endl;
}

	system("pause");
    return 0;
}

