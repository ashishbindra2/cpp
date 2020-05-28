// ore.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "iostream"
void Time(int,int,int);
void Time(int,int);
void Time(int);
void Time();
void Speed(int,int);
void pace(int,int);
int HH,MM,SS,temp,h1;
int H,m,S,z;
double time,speed,Pace,Dist;
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	double km,ms,M=0;
	double Speed;
	double Pace,temp=0;
	double h1=0,ma=0;
	int h=0,sec=0;
	
	cout<<"Enter the Time--HH/MM/SS/->"<<endl;
	cin>>H>>M>>S;
	cout<<"Enter the total Distance in km-->"<<endl;
	cin>>km;
	cout<<"Enter the total Distance in meters-->"<<endl;
	cin>>ms;
	if(H>0&&M>0&&SS>0)
		Time(H,m,S);
	else if(H>0&&m>0)
		Time(H,m);
	else if(H>0&&S>0)  
     	Time(H,S);
	else if(m>0&&S>0)
	    Time(m,S);
	else
	 Time();
	M=(double)ms/1000;
	Dist=km+M;
	cout<<"HH:"<<h<<"MM: "<<ma<<"sec: "<<sec<<endl;
	system("pause");
	return 0;
}
void Time(){
	int t=0;
	cout<<"Time is "<<t<<endl;
Speed();

}
void Time(int H,int M,int s){
	temp=(double)M/60;
	h1=(double)s/3600;
	time=H+temp+h1;
	cout<<"Time is "<<time<<endl;
Speed();

}
void Time(int H,int M){
	temp=(double)M/60;
	time=H+temp;
	cout<<"Time is "<<time<<endl;
Speed();

}
void Time(int H,int S){
	h1=(double)S/3600;
	time=H+h1;
	cout<<"Time is "<<time<<endl;
Speed();

}
void Time(int M,int S){
		temp=(double)M/60;
	h1=(double)S/3600;
	time=temp+h1;
	cout<<"Time is "<<time<<endl;
Speed();

{
MM=speed*3600-H*60;
	SS=speed*3600-H*3600;
	cout<<"Minute is ------------"<<MM<<endl;
	cout<<"Second is ------------"<<SS<<endl;
	
}
}
void Speed(){
	speed=(double)Dist/time;
	cout<<"speed is ---- "<<speed<<" Km \Hr"<<endl;
	MM=speed*60-H*60;
	SS=speed*3600-MM*3600-H*3600;
	cout<<"Minute is ------------"<<MM<<endl;
	cout<<"Second is ------------"<<SS<<endl;
	pace();
}
void pace(){
		Pace=time/Dist;
	cout<<"Pace is---- "<<Pace<<" Hr\Km"<<endl;
}