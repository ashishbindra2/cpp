// static.cpp : Defines the entry point for the console application.
//

// Staticmember.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;
class test
{
	int code;
	static int count;
public:
	void setcode(void)
	{
		code = ++count;
	}
	void showcode(void)
	{
		cout << "Object number: " << code << endl;
	}
	static void showcount(void)
	{
		cout << "cout: " << count << endl;
	}

};
int test::count;
int main()
{
	test t1, t2;
	t1.setcode();
	t2.setcode();

	test::showcount();
	test t3;
	t3.setcode();

	test::showcount();

	t1.setcode();
	t2.setcode();
	t3.setcode();

	system("pause");
    return 0;
}

