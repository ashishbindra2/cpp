// circular_quee.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
 
struct Queue
{
    int rear, front;
    int size;
    int *arr;
    Queue(int s)
    {
       front = rear = -1;
       size = s;
       arr = new int[s];
    }
 
    void enQueue(int value);
    int deQueue();
    void displayQueue();
};
 
void Queue::enQueue(int value)
{
    if ((front == 0 && rear == size-1) ||
            (rear == front-1))
    {
        cout<<"Queue is Full"<<endl;
        return;
    }
 
    else if (front == -1) /* Insert First Element */
    {
        front = rear = 0;
        arr[rear] = value;
    }
 
    else if (rear == size-1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }
 
    else
    {
        rear++;
        arr[rear] = value;
    }
}

int Queue::deQueue()
{
    if (front == -1)
    {
        cout<<"Queue is Empty"<<endl;
        return INT_MIN;
    }
 
    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size-1)
        front = 0;
    else
        front++;
 
    return data;
}

void Queue::displayQueue()
{
    if (front == -1)
    {
        cout<<"Queue is Empty"<<endl;
        return;
    }
    cout<<"Elements in Circular Queue are: ";
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            cout<<arr[i]<<"\t";
    }
    else
    {
        for (int i = front; i < size; i++)
            cout<<arr[i]<<"\t";
 
        for (int i = 0; i <= rear; i++)
           cout<< arr[i]<<"\t";
    }
	cout<<endl;
}

int main(int argc, _TCHAR* argv[])
{
    Queue q(5);
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(-6);
    q.displayQueue();
    cout<<"Deleted value = "<< q.deQueue()<<endl;
    cout<<"Deleted value = "<<q.deQueue()<<endl;
 
    q.displayQueue();
 
    q.enQueue(9);
    q.enQueue(0);
    q.enQueue(5);
 
    q.displayQueue();
 
    q.enQueue(20);
	system("pause");
    return 0;
}

