// pro4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
class Demo
{
	private:	
		static int X;
		static int Y;
	public:
	static void  Print()
	{
		cout <<"Value of X: " << X << endl;
		cout <<"Value of Y: " << Y << endl;
	}
};
int Demo :: X =10;
int Demo :: Y =20;
int main(int argc, _TCHAR* argv[])
{
	Demo OB;
	cout<<"Printing through object name:"<<endl;
	OB.Print();
	cout<<"Printing through class name:"<<endl;
	Demo::Print();
	system("pause");
	return 0;
}
