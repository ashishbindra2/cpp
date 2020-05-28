// StackPro.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;
class stack{
	#define Max 10
	int a[Max];
	int top;
	public :
		stack() {top =-1;}
int push(int x){
	if(top>=Max){
		cout<<" Stack is overflow: "<<endl;
		return top+1;
	}
	else
	{
		a[++top]=x;
		return a[top];
	}
}
int  pop()
{
	if(top<0)
	{
		cout<<" stack is under flow: "<<endl;
		return 0;
	}
	else
	{
	   int x=a[top--];
	   return x;
	}
}

bool  isEmpty(){
		return (top<0);
}
void display(){
		for( int j=Max-1;j>0;j--)
			cout<<a[j]<<" element is present "<<endl;
}
};
int _tmain(int argc, _TCHAR* argv[])
{
	  stack s;
	  int i;
for(i=0;i<Max;i++)
	cout<<s.push(i)<<" push opration "<<endl;
s.display();
    //for(i=12;i>0;i--)
		cout<<s.pop()<<" pop opration "<<endl;		
	s.display();
	s.isEmpty();
	system("pause");
	return 0;
}

