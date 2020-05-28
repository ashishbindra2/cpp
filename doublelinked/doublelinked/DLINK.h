#pragma once
struct NODE
{
	int info;
	NODE *pre;
	NODE *next;
};
class DLINK
{
	NODE *begin;
public:
	DLINK(void);
	bool isEmpty();
	void create(int);
	void insertAt_B(int);
	void insertAt_E(int);
	int deleteAt_B();
	int deleteAt_E();
	void traversB();
	void traversE();

	~DLINK(void);
};
