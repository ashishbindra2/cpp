// defaultconstructor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
class marks
{
public:
	int maths;
	int science;

	marks()
	{
		maths=0;
		science=0;
	}
	void display()
	{
		cout<<"maths : " <<maths<<endl;
		cout<<"science : " <<science<<endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	marks m;
	system("pause");
	return 0;
}
