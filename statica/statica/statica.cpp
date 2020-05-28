// statica.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;
class Test{
	int a;
	static int count;
	void co();
public:
	Test(){a=10; }
	static void display(){
		count++;
		cout<<" "<<count<<endl;
	}
	friend void ashish(Test t);
};
void ashish(Test t){
	//t.a=6;
	cout<<" "<<t.a<<endl;
}
int Test :: count;
int _tmain(int argc, _TCHAR* argv[])
{
	Test t,t1,t2;
	//for(int i=0;i<7;i++)
	//t.display();
	ashish(t1);
	//t1.display();
	//t2.display();
	system("pause");
	return 0;
}

