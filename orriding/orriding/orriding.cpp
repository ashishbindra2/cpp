// orriding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
void display(char = '*', int = 1);

void display(char c, int n)
{
    for(int i = 1; i <= n; ++i)
    {
        cout << c;
    }
    cout << endl;
}
int main()
{
    cout << "No argument passed:\n";
    display();
    
    cout << "\nFirst argument passed:\n";
    display('#');
    
    cout << "\nBoth argument passed:\n";
    display('$', 5);

	system("pause");
	return 0;
}