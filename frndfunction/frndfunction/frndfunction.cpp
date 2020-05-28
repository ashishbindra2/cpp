// frndfunction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
class Rectangle{
	int width,height;

public:
	Rectangle(int w=1, int h=1):width(w),height(h){}
	friend void display(Rectangle &);
};
void display(Rectangle &r){
	cout<<r.width * r.height<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
Rectangle(5,10);
Rectangle rect;
display(rect);
system("pause");
	return 0;
	
}

