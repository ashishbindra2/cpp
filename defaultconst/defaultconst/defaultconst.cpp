// defaultconst.cpp : Defines the entry point for the console application.
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
	marks(int marks1,int marks2)
	{
		maths=marks1;
		science=marks2;
	}
	marks(const marks &obj)
	{
		maths=obj.maths;
		science=obj.science;
	}
	 void display()
	{
		cout<<"maths : " <<maths<<endl;
		cout<<"science : "<<science<<endl;
	}
};

	

int _tmain(int argc, _TCHAR* argv[])
{
	marks m1,m2(100,200),m3;


	m1.display();
	m2.display();
	m3.display();
	system("pause");
	return 0;
}

