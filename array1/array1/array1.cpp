// array1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "time.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
int a[4][4],i,j;
srand(time(NULL));
for(i=0; i<4; i++)
{
	for(j=0; j<4; j++)
{
	a[i][j]=rand()%2;
	}}

for(i=0; i<4; i++)
{
	for(j=0; j<4; j++)
{

	cout<<a[i][j]<<"  ";
	}
	cout<<endl;
}
system("pause");
return 0;

}


	
	
	