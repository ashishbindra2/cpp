// StudInfo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "ctype.h"
using namespace std;
struct Student{
	 int RollNo;
	char Name[10];
	int Marks;
}s[10];
int _tmain(int argc, _TCHAR* argv[])
{
	int n,i,temp,flag=0;
	cout<<"Number of Student---->"<<endl;
	cin>>n;
	cout<<"Enter the detail of student student"<<endl;	
	for(i=0;i<n;i++)
	{
		
		cout<<"Roll_No "<<endl;
		cin>>s[i].RollNo;
		flag=0;
		if(s[i].RollNo<0)
		{
			cout<<"Invalid Input Rollno must be postive ";//break;
			i--; continue;
		}
		if(i!=0)
		{
		for(int j=0;j<i;j++)
		{
			if(s[i].RollNo==s[j].RollNo)
			{
				cout<<"roll alrady exist"<<endl;
				flag=1;
				i--;	
			}
		}
		    if(flag==0)				
		    {
			cout<<"Name ";
			cin>>s[i].Name;
			cout<<"Marks ";
			cin>>s[i].Marks;
		    }
			
		}
		else
		{
			cout<<"Name ";
			cin>>s[i].Name;
			cout<<"Marks ";
			cin>>s[i].Marks;
		 }
			cout<<endl;
		}
	
	cout<<"--------------------------------------------"<<endl;
	cout<<"Befor sort "<<endl;
			cout<<"Roll_No"<<"\t"<<"Name"<<"\t"<<"Marks"<<endl;
	for(i=0;i<n;i++){
		cout<<s[i].RollNo<<"\t"<<s[i].Name<<"\t"<<s[i].Marks<<endl;	
	}
	cout<<"--------------------------------------------"<<endl;
		cout<<"After sort "<<endl;
		for(i=0;i<n-1;i++){
			for(int j=0;j<n-1;j++){
			if(s[j].RollNo>s[j+1].RollNo){
				temp=s[j].RollNo;
				s[j].RollNo=s[j+1].RollNo;
				s[j+1].RollNo=temp;
			}
			}
	}
		for(i=0;i<n;i++){
		cout<<s[i].RollNo<<"\t"<<s[i].Name<<"\t"<<s[i].Marks<<endl;	
	}
	system("pause");
	return 0;
}


