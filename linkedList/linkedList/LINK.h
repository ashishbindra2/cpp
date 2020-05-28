#pragma once
struct NODE
{
	int info;
	NODE *next;
};

class CLINK
{
	NODE *begin;
public:
	CLINK(void);
	bool isEmpty();
	void create(int);
	void insertB(int);
	void insertE(int);
	int deleteB();
	int deleteE();
	void freq();
	void travers();
	~CLINK(void);
};

