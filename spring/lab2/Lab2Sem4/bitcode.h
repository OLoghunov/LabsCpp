#pragma once
#include <iostream>

class BitNode
{
public:
	bool data;
	BitNode* pNext;
	BitNode(bool data, BitNode* pNext = nullptr)
	{
		this->data = data;
		this->pNext = pNext;
	}
};

class Bitcode
{
	int size;
	BitNode* head;
public:
	Bitcode()
	{
		size = 0;
		head = nullptr;
	}

	BitNode* getHead() { return head; }

	void clear()
	{
		while (size)
			popFront();
	}

	void popFront()
	{
		if (this->size)
		{
			BitNode* temp = head;
			head = head->pNext;
			delete temp;
			size--;
		}
	}

	void push(bool bit)
	{
		if (head == nullptr)
			head = new BitNode(bit);
		else
		{
			BitNode* cur = this->head;
			while (cur->pNext != nullptr)
				cur = cur->pNext;
			cur->pNext = new BitNode(bit);
		}
		size++;
	}

	int getSize() { return size; }

	friend std::ostream& operator<<(std::ostream& s, Bitcode& code)
	{
		int count = 1;
		BitNode* current = code.head;
		while (count <= code.size) {
			s << current->data;
			current = current->pNext;
			count++;
		}
		return s;
	}
};