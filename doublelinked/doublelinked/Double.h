#pragma once
struct NODE{
	int info;
	NODE *next;
	NODE *pre;
};
class CDouble
{
	NODE *list;//contain address of 1st node
public:
bool isEmpty();
	void createNode(int);
	void addAtBeg(int);
	void addAtLast(int);
	int deleteAtBeg();
	int deleteAtLast();
	void traversS();
	void traversE();
	void distroy();
	CDouble(void);
	~CDouble(void);
};

