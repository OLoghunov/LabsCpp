#pragma once
#include <iostream>
#include "Node.h"
class Queue
{
	unsigned size;
	Node* head;

public:
	Queue();
	~Queue();
	void PushBack(intNode* data);
	intNode* GetTop()
	{
		intNode* temp = head->data;
		PopFront();
		return temp;
	}
	void PopFront();
	int GetSize() { return size; };
	void Clear();
};