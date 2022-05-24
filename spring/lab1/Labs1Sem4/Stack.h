#pragma once
#include <iostream>
#include "StackNode.h"

using namespace std;

template <typename T>
class Stack
{
public:
	Stack()
	{
		size = 0;
		head = nullptr;
	}
	~Stack() { Clear(); }
	void Push(TreeNode<T>* data)
	{
		head = new StackNode<T>(data, head);
		size++;
	}
	TreeNode<T>* GetTop()
	{
		TreeNode<T>* temp = head->getData();
		PopFront();
		return temp;
	}
	void PopFront()
	{
		if (this->size)
		{
			StackNode<T>* temp = head;
			head = head->pNext;
			delete temp;
			size--;
		}
	}
	int GetSize() { return size; };
	void Clear()
	{
		while (size)
			PopFront();
	}

	StackNode<T>* head;
private:
	
	int size;
	
};
