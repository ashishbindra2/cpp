// static.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "time.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

int a[5][5],i,j;
srand(time(null));
for(i=0; i<5; i++)
{
	for(j=0; j<5; j++)
{
	a[i][j]=rand()%100;

	}}

for(i=0; i<5; i++)
{
	for(j=0; j<5; j++)
{

	cout<<a[i][j]<<"  ";
	}
	cout<<endl;
}
system("pause");
return 0;

}

