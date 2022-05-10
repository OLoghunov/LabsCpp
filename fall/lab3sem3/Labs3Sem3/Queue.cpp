#include "Queue.h"

Queue::Queue()
{
	size = 0;
	head = nullptr;
}

Queue::~Queue()
{
	Clear();
}

void Queue::PushBack(intNode* data)
{
	if (head == nullptr)
		head = new Node(data);
	else
	{
		Node* cur = this->head;
		while (cur->pNext != nullptr)
			cur = cur->pNext;
		cur->pNext = new Node(data);
	}
	size++;
}

void Queue::PopFront()
{
	if (this->size)
	{
		Node* temp = head;
		head = head->pNext;
		delete temp;
		size--;
	}
}

void Queue::Clear()
{
	while (size)
		PopFront();
}