// STATIC1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
 void func(void)

int _tmain(int argc, _TCHAR* argv[])
{
	
	 static int count =10;
 
	 while(count-)
	 {
		 func();
	 }

	return 0;
}

