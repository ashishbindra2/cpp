#pragma once
class cqueue
{
public:
	cqueue(void);
	~cqueue(void);
	void enqueue();
	void dequeue();
	bool IsEmpty();
	bool IsFull();
};

