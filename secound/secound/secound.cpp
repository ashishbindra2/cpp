// secound.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"

using namespace std;
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int l, int r)//abc,l=0,r=2//2nd//abc,1,2
{
   int i;
   if (l == r)
     cout<< a<<endl;
   else
   {
       for (i = l; i <= r; i++)//0,2//1,2
       {
          swap((a+l), (a+i));//abc+0,abc+0//abc+1
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
}

int _tmain(int argc, _TCHAR* argv[])
{
    char str[] = "ABC";
    int n = strlen(str);
    permute(str, 0, n-1);//"abc",0,2
	system("pause");
    return 0;
}


