// demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;
class base {};
class derived:  public base {};
int _tmain(int argc, _TCHAR* argv[])
{
	derived d;
	try {throw d;}
	catch (base b)
	{
		cout << 1;
	}
	catch (derived d)
	 {
	cout << 2;
     }	
	cout<<endl;
system("pause");
	return 0;
}

