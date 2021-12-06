#pragma once
#include <iostream>
using namespace std;
class Stack
{
public:
	Stack();
	~Stack();
	void Push(int data);
	int GetTop();
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

private:
	struct Node
	{
		Node* pNext;
		int data;
		Node(int data = int(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	unsigned size;
	Node* head;
};