// string_revers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <string.h>
#include <stdlib.h>

using namespace std;
struct Stack
{
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*) malloc(stack->capacity * sizeof(char));
    return stack;
}
int isFull(struct Stack* stack)
{   return stack->top == stack->capacity - 1; }
int isEmpty(struct Stack* stack)
{   return stack->top == -1;  }

void push(struct Stack* stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}
char pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
void reverse(char str[])
{
    int n = strlen(str);
    struct Stack* stack = createStack(n);
    int i;
    for (i = 0; i < n; i++)
        push(stack, str[i]);

    for (i = 0; i < n; i++)
        str[i] = pop(stack);
}

int _tmain(int argc, _TCHAR* argv[])
{
    char str[] = "MCA";
    reverse(str);
    cout<<" Reversed string is "<<str<<endl;
    system("pause");
    return 0;
}

