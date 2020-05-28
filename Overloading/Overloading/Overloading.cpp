// Overloading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;
 void add();
 int add(int);
 int add(int,int);
 double add(double);
 double add(double,double);
 char add(char ,char);
int _tmain(int argc, _TCHAR* argv[])
{
	int y;
	add();
	y=add(1);
	cout<<"sum of single integer"<<y<<endl;
	add(1,2);
	add(2.44);
    add(2.33,4.33);
	add('m','k');
	system("pause");
	return 0;
}
void add(){
	int x=1,y=2;
	       cout<<"sum of x and y is  "<<x+y<<endl;
}
int add(int x){
	int a;
	a=x+x;
	
	return(a);
}
void add(int x,int y){
	cout<<x+y<<endl;
}
void add(double t){
	cout<<t+t<<endl;
}
void add(double a,double b){
	cout<<a+b<<endl;
}
void add(char k,char b){
	cout<<k+b<<endl;

}
