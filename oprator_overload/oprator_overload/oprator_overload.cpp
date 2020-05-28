// oprator_overload.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;
class cal{
 int a,b;
public:
	cal(int x=0,int y=0){a=x;b=y; }
	cal operator +(cal obj){
		cal t;
		t.a=obj.a+a;//30+10
		t.b=obj.b+b;
		return t;
	}
	cal operator -(cal const &obj){
		cal t;
		t.a=obj.a-a;
		t.b=obj.b-b;
		return t;
	}
	cal operator *(cal const &obj){
		cal t;
		t.a=obj.a*a;
		t.b=obj.b*b;
		return t;
	}
	cal operator ++(){
		cal t;
		t.a=++a;
		cout<<"pre:-"<<endl;
		return t;

	}
	cal operator ++(int v){
		cal t;
		t.a=a++;
		cout<<"post:-"<<endl;
		return t;
	}
	void display(){
	cout<<a<<"\t"<<b<<endl;
	}
	
	void display1(){
	cout<<a<<endl;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	cal c1(10,20), c2(30,40);
	cal c3=c1+c2;
	cal c4=c1-c2;
	cal c5=c1*c2;
	c3.display();
	c4.display();
	c5.display();
	cal obj1,obj2;
	obj1=++obj2;
	obj1.display1();
	obj2.display1();
	obj1=obj2++;
	obj1.display1();
	obj2.display1();

    
	system("pause");
	return 0;
}

