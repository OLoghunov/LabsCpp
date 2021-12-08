#pragma once
#include "intNode.h"
struct Node
{
	Node* pNext;
	intNode* data;
	Node(intNode* data, Node* pNext = nullptr)
	{
		this->data = data;
		this->pNext = pNext;
	}
};
