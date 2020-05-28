#pragma once
class CHeap
{
	int *A;
	int size;
	int count;
public:
	CHeap();
	CHeap(int n);
	~CHeap();
	bool IsEmpty();
	bool IsFull();
	void swap(int &x,int &y);
	void Insert(int val);
	int GetParent(int index);
	void GetChildren(int index,int *LChild, int *RChild);
	void Heapify();
	void sort();
	void Disp();
};



