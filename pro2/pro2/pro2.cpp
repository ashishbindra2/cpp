// pro2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
   double a[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
   double *p;
   p = a;
   cout << "Values of an array:---" << endl;
   for ( int i = 0; i < 5; i++ ) {
      cout << a[i] << endl;
   }

   cout << "Array values using pointer " << endl; 
   for ( int i = 0; i < 5; i++ ) {
      cout << *p << endl;
	  p++;
   }
 
 
	system("pause");
	return 0;
}

