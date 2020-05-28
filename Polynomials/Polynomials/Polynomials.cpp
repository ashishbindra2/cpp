// Polynomials.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
struct Node{
	int data;
	int pow;
	struct Node *next;
}; 
void create_node(int x, int y, struct Node **temp)
{
   struct Node *r, *z;
    z = *temp;
    if(z == NULL)
    {
        r =(struct Node*)malloc(sizeof(struct Node));
        r->data = x;
        r->pow = y;
        *temp = r;
        r->next = (struct Node*)malloc(sizeof(struct Node));
        r = r->next;
        r->next = NULL;
    }
    else
    {
		r->data = x;
        r->pow = y;
        r->next = (struct Node*)malloc(sizeof(struct Node));
        r = r->next;
        r->next = NULL;
    }
}

void display1(struct Node *node)
{
while(node->next != NULL)
    {
    cout<<node->data<<node->pow;
    node = node->next;
    if(node->next != NULL)
        cout<<" + ";
    }
}
void add(struct Node *poly1, struct Node *poly2, struct Node *poly)
{
while(poly1->next && poly2->next)
    {
        // If power of 1st polynomial is greater then 2nd, then store 1st as it is
        // and move its pointer
        if(poly1->pow > poly2->pow)
        {
            poly->pow = poly1->pow;
            poly->data = poly1->data;
            poly1 = poly1->next;
        }
        
        // If power of 2nd polynomial is greater then 1st, then store 2nd as it is
        // and move its pointer
        else if(poly1->pow < poly2->pow)
        {
            poly->pow = poly2->pow;
            poly->data = poly2->data;
            poly2 = poly2->next;
        }
        
        // If power of both polynomial numbers is same then add their coefficients
        else
        {
            poly->pow = poly1->pow;
            poly->data = poly1->data+poly2->data;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        
        // Dynamically create new node
        poly->next = (struct Node *)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }
while(poly1->next || poly2->next)
    {
        if(poly1->next)
        {
            poly->pow = poly1->pow;
            poly->data = poly1->data;
            poly1 = poly1->next;
        }
        if(poly2->next)
        {
            poly->pow = poly2->pow;
            poly->data = poly2->data;
            poly2 = poly2->next;
        }
        poly->next = (struct Node *)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }
}
int _tmain(int argc, _TCHAR* argv[])
{
	struct Node *poly1=NULL,*poly2=NULL,*poly3=NULL;
	create_node(5,3,&poly1);
	create_node(3,2,&poly1);
	create_node(3,0,&poly1);

	create_node(3,2,&poly2);
	create_node(3,1,&poly2);
	create_node(3,0,&poly2);

	display1(poly1);
	display1(poly2);
poly3 = (struct Node *)malloc(sizeof(struct Node));
	add(poly1,poly2,poly3);
	display1(poly3);
	system("pasue");
	return 0;
}

