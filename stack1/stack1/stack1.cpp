// stack1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#define MAX 10
using namespace std;

class stack
{
private:
	int num[MAX];
	int top;

public:
	stack();
	int push(int);
	int pop();
	int isempty();
	int isfull();
	void display();
};
stack::stack()
{
	top=-1;
}
int stack::isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int stack::isfull()
{
	if(top==(MAX-1))
		return 1;
	else
		return 0;
}
int stack::push(int n)
{
	if(isfull())
	return 0;
	
	num[top]=n;
	++top;
	return n;
}

int stack::pop()
{
	int temp;
	if(isempty())
		return 0;
	temp=num[top];
	--top;
	return temp;
}
void stack::display()
{
	int i;
	cout<<"element of stack are :-->"<<endl;
	for(i=(top-1);i>=0;i--)
	cout<<num[i]<<" "<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	stack stk;
	for(char i='A';i<MAX;i++)
	stk.push(i);
	stk.display();
	stk.isfull();
	stk.pop();
	stk.pop();
	stk.pop();
	stk.display();

	system("pause");
	return 0;
}

