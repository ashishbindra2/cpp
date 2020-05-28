#include "StdAfx.h"
#include "LINK.h"
#include "iostream"
using namespace std;
CLINK::CLINK(void)
{
	begin=NULL;
}
bool CLINK:: isEmpty(){
	if(begin==NULL)
		return true;
	return false;
}
void CLINK::create(int val){
	if(isEmpty()){
		NODE *temp = new NODE;
		begin=temp;
		temp->info=val;
		temp->next=NULL;
	}
}
void CLINK::insertB(int val){
	if(isEmpty())
		create(val);
	else
	{
		NODE *temp = new NODE;
		temp ->info=val;
		temp->next=begin;
		begin=temp;
	}
}

void CLINK::insertE(int val){
	if(isEmpty())
		create(val);
	else
	{
		NODE *temp = new NODE;
		temp ->info=val;
		temp->next=NULL;
		NODE *q=begin;
		while(q->next!=NULL){
			q=q->next;
		}
		q->next=temp;
	}
}
int CLINK::deleteB(){
	int val =-1;
	if(!isEmpty())
	{
		NODE *temp = new NODE;
		temp= begin;
		begin=begin->next;
		val=temp->info;
		delete temp;
	}
	return val;
}
int CLINK::deleteE(){
	int val =-1;
	if(!isEmpty()){
	if(begin->next==NULL)
		deleteB();
	else
	{
		NODE *q ;
		NODE *temp; 
		q=begin;
		while(q->next->next != NULL)
			q=q->next;
		temp= q->next;
		q->next=NULL;
		val=temp->info;
		delete temp;
	}
	return val;
	}
	
}
void CLINK::travers(){
	if(!isEmpty())
	{
		NODE *q;
		q=begin;
		while(q!=NULL)
		{
			cout<<q->info<<"\t";
			q=q->next;
		}
cout<<endl;
	}
	else
		cout<<"List is Empty:-->"<<endl;
}
void CLINK :: freq(){
int i,j,c,f=1;
i=j=c=0;
NODE *q,*r;
q=r=begin;
while(q!=NULL)
{
	i++;f=1;c=0;j=0;
	int t= q->info;
	while(r!=NULL)
	{
		j++;
		if(t==r->info)
		{
			if(j<i)f=0;
			c=c+1;
		}
		r=r->next;
	}
	r=begin;
	q=q->next;
	if(f==1)
		cout<<"frequenc of "<<t<<" is "<<c<<endl;
}
}
CLINK::~CLINK(void)
{
}
