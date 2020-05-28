#pragma once
struct NODE{
	int info;
	NODE *pre,*next;
}
class CIRCLE
{
	NODE *begin;
public:
	CIRCLE(void);
	bool isEmpty();
	void create(int);
	void insertionB(int);
	void insertionE(int);
	int deleteB();
	int deleteE();
	void triversS();
	~CIRCLE(void);
};

