// pro5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"iostream"
using namespace std;
class Shape{
		int L,B;
public:
	Shape(){L=10;	B=20;}
friend class Square;        //Statement 1
friend void Rectangle(Shape s);
};
void Rectangle(Shape s)
	{
		cout<<"area of rectangle:-"<<(s.L)*(s.B)<<endl;		
	};
	class Square
	{
		
		public:
			void side(Shape s){
			cout<<"area of square:-"<<s.L*s.L<<endl;
			}
	};
	int main(int argc, _TCHAR* argv[])
	{
		Shape S;
		Rectangle(S);
		Square sq;
		sq.side(S);
		system("pause");
		return 0;
	}
