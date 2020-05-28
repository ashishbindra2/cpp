// Friendclass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;
class Square{
private : 
		int a;
public :
	Square(){a=5;}
	friend void side(Square s);
};
void side(Square s){
	cout<< ((s.a)*(s.a))<<endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	Square s;
	side(s);
	system("pause");
	return 0;
}

