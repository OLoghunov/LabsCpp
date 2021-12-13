#pragma once
#include <iostream>

using namespace std;

template <class T>

class Stack
{
	struct Node
	{
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size;
	Node* head;
public:
	Stack();
	~Stack();
	void Push(T data);
	T GetTop();
	void PopFront();
	int GetSize() { return size; };
	void Clear();
	
	friend std::ostream& operator<<(std::ostream& s, Stack& list)
	{
		unsigned count = 1;
		Node* current = list.head;
		while (count <= list.size) {
			s << current->data << '\t';
			current = current->pNext;
			count++;
		}
		return s;
	}
};