// multilevelinheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"iostream"
using namespace std;

class first {
public:first(){
	cout<<"AShish"<<endl;
	   }
	   };
class sec : public first{
public:	
	sec(){
	cout<<"sec"<<endl;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	first ob;
	
	system("pause");
	return 0;
}

