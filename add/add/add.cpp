// add.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;
class poly
{
	int exp;
	int coeff;
	poly *next;
public:
	void input1();
	void input2();
	void display();
	void add();
};
poly *poly1,*poly2,*poly3;
void poly::input1()
{
	int num;
	cout<<"numbers of ploynomials"<<endl;
	cin>>num;
	int c,e,i;
	for(i=0;i<=num;i++)
	{
		m:cout<<"exponent:"<<endl;
		cin>>e;
		if(e>num)
		{
			cout<<"invalid "<<endl;	
			goto m;
		}
		cout<<"coff:-"<<endl;
		cin>>c;
		poly *temp1;
		temp1=head1;
		if(temp1==NULL)
		{
			temp1=new poly;
			temp1->exp=e;
			temp1->coeff=c;
			temp1->next=NULL;
			head1=temp1;
		}
		else
		{
			temp1=head1;
			poly *r;
			r=new poly;
			while(temp1->next!=NULL)
			{
				temp1=temp1->next;
			}
			r->exp=e;
			r->coeff=e;
			temp1->next=r;
			r=next=NULL;
		}
	}
}
void poly::input2()
{
	int num;
	cout<<"numbers of ploynomials"<<endl;
	cin>>num;
	int c,e,i;
	for(i=0;i<=num;i++)
	{
m:cout<<"exponent:"<<endl;
		cin>>e;
		if(e>num)
		{
			cout<<"invalid "<<endl;	
			goto m;
		}
		cout<<"coff:-"<<endl;
		cin>>c;
		poly *temp2;
		temp2=head2;
		if(temp1==NULL)
		{
			temp2=new poly;
			temp2->exp=e;
			temp2->coeff=c;
			temp2->next=NULL;
			head2=temp2;
		}
		else
		{
			temp2=head2;
			poly *r;
			r=new poly;
			while(temp2->next!=NULL)
			{
				temp2=temp2->next;
			}
			r->exp=e;
			r->coeff=e;
			temp2->next=r;
			r=next=NULL;
		}
	}
}
void poly::add()
{
	if(head==NULL)
		head3=head2;
	if(head2==NULL)
		head3=head1;
	if(head)
}
int _tmain(int argc, _TCHAR* argv[])
{

	system("pause");
	return 0;
}

