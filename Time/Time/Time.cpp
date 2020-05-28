// Time.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;
struct Get_Time{
	int HH;
	int MM;
	int ss;
}t1;//strucuter for geting Time
int _tmain(int argc, _TCHAR* argv[])
{
	double Dist,km,ms,M=0;
	double Speed,Time;
	double Pace,temp=0;
	double h1;
	cout<<"Enter the Time--HH/MM/SS/->"<<endl;
	cin>>t1.HH>>t1.MM>>t1.ss;
	if(t1.MM>0)
		temp=(double)t1.MM/60;
	if(t1.ss>0)
		h1=(double)t1.ss/3600;
	Time=t1.HH+temp+h1;
	cout<<"Time is "<<Time<<endl;
	cout<<"Enter the total Distance in km-->"<<endl;
	cin>>km;
	cout<<"Enter the total Distance in meters-->"<<endl;
	cin>>ms;
	M=(double)ms/1000;
	Dist=km+M;
	Speed=(double)Dist/Time;
	cout<<"speed is ---- "<<Speed<<" Km \Hr"<<endl;
	Pace=Time/Dist;
	cout<<"Pace is---- "<<Pace<<" Hr\Km"<<endl;
	system("pause");
	return 0;
}

