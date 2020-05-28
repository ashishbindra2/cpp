// frndfunc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
class A
{
	int a;
public:
	A(){ a=0;}
};
class B
{
private:
	int b;
public:
	void showA(A &x)
	{
		std::cout<<"A::a="<<x.a;
	} 
};
	
int _tmain(int argc, _TCHAR* argv[])
{  
	A a;
    B b;
    b.showA(a);
	system("pause");
	return 0;

}
