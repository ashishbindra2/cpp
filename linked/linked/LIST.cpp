#include "StdAfx.h"
#include "LIST.h"
#include "iostream"
using namespace std;
CLIST::CLIST(void)
{
	list=NULL;
}
bool CLIST :: isEmpty(){
	if(list==NULL)
		return true;
	return false;
	
}
void CLIST :: createNode(int value){
	NODE *temp;
	temp = new NODE;
	if(temp!=NULL){
	temp -> info = value;	
	temp->next=NULL;
	}
	list=temp;
}
void CLIST::addAtBeg(int value){
	if(isEmpty())
		createNode(value);
	else{
			NODE *temp;
			temp=new NODE;
			temp -> info = value;
			temp ->next=list;
			list=temp;
	}
}
void CLIST::addAtLast(int value){
	if(isEmpty())
		createNode(value);
	else{
		NODE *temp;
		temp=new NODE;
		if(temp!=NULL)
		{
			temp -> info = value;
			temp ->next=NULL;
			NODE *q;
			q=list;
			while(q->next!=NULL)
			{
				q=q->next;
			}
			q->next=temp;
		}
	}
}
int CLIST::deleteAtBeg(){
	int value=-1;
	if(!isEmpty())
	{
		NODE *temp;
		temp =list;
		list=list->next;
		value=temp->info;
		delete temp;
	}
	return value;
}
int CLIST:: deleteAtLast(){
	int value=-1;
	if(!isEmpty())
	{
		if(list->next==NULL)
		{
			deleteAtBeg();
		}
	
	else
	{
		NODE *q;
		q=list;
		while(q->next->next!=NULL)
				q=q->next;
			NODE *temp;
			temp=q->next;
			q->next=NULL;
			value=temp->info;
			delete temp;
			
	}
	return value;
	}
}

void CLIST:: travers(){
	if(!isEmpty())
	{
		NODE *q;
		q=list;
		while(q!=NULL)
		{
			cout<<q->info<<"\t";
			q=q->next;
		}
		cout<<endl;
	}
	else
	{
		cout<<"LIST is empty"<<endl;
	}
}
void CLIST :: distroy()
{
	
}
CLIST::~CLIST(void)
{
}
