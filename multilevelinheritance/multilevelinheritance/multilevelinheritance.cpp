// multilevelinheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"iostream"
using namespace std;

class Base{

protected:
	int a;
public:
	int b;
private:
	int c;
};
class Derived1:public Base{
	public:
	int a;
	int b;
	void disp()
	{
		a=40;
		b=60;
		cout<<a<<endl<<b<<endl;
	}
};
class Derived2:public Derived1{
public:
	int a;
	int b;
	void disp()
	{
			cout<<a<<endl<<b<<endl;
	}
};
	
int _tmain(int argc, _TCHAR* argv[])
{
	Derived2 obj;
	obj.Derived1::disp();
	system("pause");
	return 0;
}

