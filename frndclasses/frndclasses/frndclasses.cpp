// frndclasses.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
class Square;
class Rectangle{
	int width,height;
public:
	Rectangle(int w=1, int h=1):width(w),height(h){}
	void display(){
		cout<<"Rectangle:"<<width * height<<endl;
	};
	void morph(Square &);
};
class Square{
	int side;
public:
	Square(int s=1):side(s){}
	void display(){
		cout<<"Square:" <<side * side<<endl;
	};
	friend class Rectangle;
};
void Rectangle::morph(Square &s){
	width=s.side;

height=s.side;

}	
int _tmain(int argc, _TCHAR* argv[])
{
	Rectangle(5,10);
	Rectangle rec;
	Square sq(5);
	cout<<"Before:"<<endl;
	rec.display();
	sq.display();
	rec.morph(sq);
	cout<<"\n\After:"<<endl;
	rec.display();
	sq.display();
	system("pause");
	return 0;
}

