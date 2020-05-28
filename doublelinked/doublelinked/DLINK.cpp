#include "StdAfx.h"
#include "DLINK.h"
#include "iostream"

using namespace std;
DLINK::DLINK(void)
{
	begin = NULL;
}
bool DLINK::isEmpty(){
	if(begin==NULL)
		return true;
	return false;
}
void DLINK::create(int val){
	NODE *temp = new NODE;
	temp -> info = val;
	temp->next=temp->pre=NULL;
	begin = temp;
}
void DLINK::insertAt_B(int val){
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
void DLINK::insertAt_E(int val){
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
	int DLINK::deleteAt_B(){
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
	int DLINK::deleteAt_E(){
		int val = -1;
		if(!isEmpty())
		{
			if(begin->next==NULL)
			    val=deleteAt_B();
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
	void DLINK::traversB(){
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
	void DLINK::traversE(){
	if(!isEmpty())
		{
			NODE *q,*end ;
			q=begin;
			while(q->next!=NULL)
			{
				q=q->next;
			}
			end=q;
			while(end!=NULL)
			{
				cout<<end->info<<"\t";
				end=end->pre;
			}
			cout<<endl;
		}
		else
			cout<<"List is Empty ->"<<endl;
	}

DLINK::~DLINK(void)
{
}
