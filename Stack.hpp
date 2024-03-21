#define MAX_ARRAY_SIZE 100

#include <iostream>

class Stack
{
private:
	int stack[MAX_ARRAY_SIZE];
	int topIndex;

public:
	Stack();
	void Push(int num);
	int Pop();
	int Peek();
	bool IsEmpty();
};