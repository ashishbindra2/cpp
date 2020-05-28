#include "StdAfx.h"
#include "Double.h"
#include "iostream"
using namespace std;

CDouble::CDouble(void)
{
		list=NULL;
}
bool CDouble :: isEmpty(){
	if(list==NULL)
		return true;
	return false;	
}
void CDouble :: createNode(int value){
	NODE *temp;
	temp = new NODE;
	if(temp!=NULL){
	temp -> info = value;	
	temp -> next = NULL;
	temp -> pre = NULL;
	}
	list=temp;
}
void CDouble :: addAtBeg(int value){
	if(isEmpty())
		createNode(value);
	else
	{
		NODE *temp;
		temp=new NODE;
		temp -> info = value;
		temp -> next = list;
		temp ->pre = NULL;
		list=temp;
	}
}
void CDouble :: addAtLast(int value){
	if(isEmpty())
		createNode(value);
	else{
		NODE *temp;
		temp = new NODE;
		if(temp!=NULL)
		{
			temp -> info = value;
			temp -> next = NULL;
			temp -> pre = NULL;//
			NODE *q;
			q = list;
			while(q -> next != NULL)
			{
				q=q->next;
			}
			q->next=temp;
		}
	}
}
int CDouble :: deleteAtBeg(){
	int value =-1;
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
int CDouble :: deleteAtLast(){
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
		while(q -> next -> next!=NULL)
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
void CDouble :: traversS(){
	if(!isEmpty())
	{
		NODE *q;
		q=list;
		while(q!=NULL)
		{
			cout<<"triverse from starting:--"<<endl;
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

void CDouble :: traversE(){
	if(!isEmpty())
	{
		NODE *q;
		q=list;
		while(q!=NULL)
		{
			cout<<"triverse from END :--"<<endl;
			cout<< q- > info<<"\t";
			q = q -> pre;
		}
		cout<<endl;
	}
	else
	{
		cout<<"LIST is empty"<<endl;
	}
}

CDouble::~CDouble(void)
{
}
