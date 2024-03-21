#include "Stack.hpp"

Stack::Stack()
{
	topIndex = 0;
}

void Stack::Push(int num)
{
	if (topIndex >= MAX_ARRAY_SIZE - 1)
	{
		std::cout << "Stack overflow!" << std::endl;
	}
	else
	{
		topIndex++;
		stack[topIndex] = num;
	}
}

int Stack::Pop()
{
	if (topIndex <= 0)
	{
		std::cout << "Stack underflow!" << std::endl;
		return -1;
	}
	else
	{
		topIndex--;
		return stack[topIndex + 1];
	}
}

int Stack::Peek()
{
	if (IsEmpty())
	{
		std::cout << "Stack is empty!" << std::endl;
		return -1;
	}
	else
	{
		return stack[topIndex];
	}
}

bool Stack::IsEmpty()
{
	return topIndex == 0;
}