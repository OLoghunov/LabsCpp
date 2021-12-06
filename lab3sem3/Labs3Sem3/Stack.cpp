#include "Stack.h"

Stack::Stack()
{
	size = 0;
	head = nullptr;
}

Stack::~Stack()
{
	Clear();
}

void Stack::Push(int data)
{
	head = new Node(data, head);
	size++;
}

int Stack::GetTop()
{
	int temp = head->data;
	PopFront();
	return temp;
}

void Stack::PopFront()
{
	if (this->size)
	{
		Node* temp = head;
		head = head->pNext;
		delete temp;
		size--;
	}
}

void Stack::Clear()
{
	while (size)
		PopFront();
}
