// indexSAerquentialAcess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "fstream"

using namespace std;
class Info{
	int id;
	char c[20];
public:
	void getdata(){
		cout<<"Enter the roll_number:---->"<<endl;
		cin>>id;
		cout<<"Enter name of student:---->"<<endl;
		cin>>c;
	}
	void display(){
		cout<<"id "<<id<<"student name "<<c<<endl;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Info in[5];
	ofstream file1, file2;
	file1.open("index.txt");
		for(int i=1;i<=2;i++){
			in[i].getdata();
			file1.write((char*)&in[i],sizeof(Info));
		}
	for(int i=0;i<2;i++)
	     in[i].display();
	file1.close();
	file2.open("detail.txt");
	file2.close();
	system("pause");
	return 0;
}

