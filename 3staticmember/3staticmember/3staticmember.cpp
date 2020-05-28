// 3staticmember.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
class stat{
	int code;
	static int count;
public:
	stat()
	{
		code=++count;
	}
	void showcode()
	{
		cout<<"\n\objects no. is:"<<code;
	}
	static void showcount()
	{
		cout<<"\n\count objects:"<<count;
	}};
	int stat::count;


int _tmain(int argc, _TCHAR* argv[])
{
	stat obj1,obj2;
		obj1.showcount();
		obj1.showcode();
		obj2.showcount();
		obj2.showcode();
	
	return 0;
}
	
