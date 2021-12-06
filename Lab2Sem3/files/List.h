#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;
class List
{

public:
	List();
	~List();
	void PushBack(int data);
	void PushFront(int data);
	void PopBack();
	void PopFront();
	void Insert(int data, int index);
	int At(int index);
	void Remove(int index);
	int GetSize() { return size; };
	void Clear();
	void Set(int data, int index);
	bool IsEmpty();
	void Swap(int index1, int index2);
	bool IsCorrect();
	int FindFirst(List& S);
	int& operator[](const int index);
	friend std::ostream& operator<<(std::ostream& s, List& list)
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
#endif