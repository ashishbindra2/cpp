#include "StdAfx.h"
#include "IRCLE.h"
#include "iostream"

using namespace std;

CIRCLE::CIRCLE(void)
{
	begin=NULL;
}

bool CIRCLE:: isEmpty(){
	if(begin==NULL)
		return true;
	return false;
}
void CIRCLE:: create(int val){
	if(isEmpty()){
		NODE *temp = new NODE;
		temp->next=temp->pre;
		begin= temp;
	}
}
void CIRCLE:: insertionB(int val){
	if(isEmpty())
		create(val);
	else
	{
		NODE *temp = new NODE;
		temp -> info = val;
		temp ->next = begin;
		begin->pre = temp;
		begin= temp;
	}

}
void CIRCLE:: insertionE(int val){
if(isEmpty())
		create(val);
	else
	{
		NODE *temp = new NODE;
		temp -> info = val;
		temp ->next = NULL;
		
		NODE *q;
		q=begin;

		while(q -> next!= NULL)
		{
			q = q -> next;
		}
		q ->next= temp;
		temp ->pre= q;
	}
}
int CIRCLE::deleteB(){
int val = -1;
		if(!isEmpty())
		{
			NODE *temp = begin;
			begin = begin ->next;
			if(begin!=NULL)
				begin ->pre= NULL;
			val = temp->info;
			delete temp;
		}
		return val;
}
int CIRCLE :: deleteE(){
	int val = -1;
		if(!isEmpty())
		{
			if(begin->next==NULL)
			    val=deleteB();
			else{
				NODE *q ;
				q=begin;
				while(q->next->next!=NULL)
					q=q->next;
				NODE *temp =q->next;
				q->next = NULL;
				val= temp->info;
				delete temp;
			}
		}
			return val;
}
void CIRCLE:: triversS(){
		if(!isEmpty())
		{
			NODE *q =begin;
			while(q!=NULL)
			{
				cout<<q->info<<"\t";
				q=q->next;
			}
			cout<<endl;
		}
		else
			cout<<"List is Empty ->"<<endl;
}
CIRCLE::~CIRCLE(void)
{
}
