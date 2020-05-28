// parameterizedconst.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
class Point
{
private:
	int x,y,P1,P2;
	
public:
	Point(int x1,int y1)
	{
		x=x1;
	y=y1;

	}
	int getX()
	{return x;}
	int getY()
	{return y;}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Point P1(10,15);
	cout<<"P1.x=" <<P1.getX()<<endl<<"P1.y="<<P1.getY()<<endl;
	system("pause");
	return 0;
}

