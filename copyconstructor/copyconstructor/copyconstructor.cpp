// copyconstructor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
class Point
{
private:
	int x,y,x1,y1,P1,P2 ;
public:
	Point(int x1,int y1)
	{
		x=x1; 
		y=y1;
	}
	Point(const Point &P2)
	{
		x=P2.x;
		y=P2.y;
	}
	int getX() {return x;}
	int getY() {return y;}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Point P1(10,15);
		Point P2=P1;
	cout<<"P1.x=" <<P1.getX()<<" P1.y="<<P1.getY()<<endl;
	cout<<"P2.x=" <<P2.getX()<<" P2.y="<<P2.getY();
	system("pause");
	return 0;
}

